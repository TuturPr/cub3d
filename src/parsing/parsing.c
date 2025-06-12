/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:46:27 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 16:18:01 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

static bool	ij_loop(const char *line, int values[3])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i] && j < 3)
	{
		if (line[i] >= '0' && line[i] <= '9')
			values[j] = values[j] * 10 + (line[i] - '0');
		else if (line[i] == ',')
		{
			j++;
			if (j >= 3)
				return (0);
		}
		else if (line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	if (j != 2)
		return (0);
	return (1);
}

unsigned int	parse_rgb_line(const char *line)
{
	int	i;
	int	j;
	int	k;
	int	values[3];

	i = 0;
	j = 0;
	k = 0;
	ft_memset(values, 0, sizeof(values));
	ij_loop(line, values);
	while (k++ < 3)
	{
		if (values[k] < 0)
			values[k] = 0;
		if (values[k] > 255)
			values[k] = 255;
	}
	return ((values[0] << 24) | (values[1] << 16) | (values[2] << 8) | 255);
}

static bool	is_ber_file(const char *argv)
{
	char	*extension;

	extension = ft_strrchr(argv, '/');
	if (!extension)
		extension = (char *)argv;
	extension = ft_strrchr(extension, '.');
	if (extension && ft_strncmp(extension, ".cub", ft_strlen(extension)) == 0)
		return (true);
	return (false);
}

int	open_map(t_data *data, char *path)
{
	int	fd;

	if (!is_ber_file(path))
		return (exit_error(data, "Invalid file extension"), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (exit_error(data, "Cannot open map"), -1);
	return (fd);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char	**map_open(t_data *data, char *path, char **map_data)
{
	char	*line;
	char	*new_maps;
	int		fd_map;
	char	*maps;
	char	*temp;

	maps = ft_strdup("");
	if (!maps)
		return (NULL);
	fd_map = open_map(data, path);
	line = get_next_line(fd_map);
	if (!line)
	{
		close(fd_map);
		free(maps);
		exit_error(data, "Map file is empty");
	}
	while (line)
	{
		if (line[0] == '\n')
		{
			temp = ft_strjoin(line, "_\n");
			free(line);
			line = temp;
		}
		new_maps = ft_strjoin(maps, line);
		free(maps);
		free(line);
		if (!new_maps)
		{
			close(fd_map);
			return (NULL);
		}
		maps = new_maps;
		line = get_next_line(fd_map);
	}
	close(fd_map);
	map_data = ft_split(maps, '\n');
	free(maps);
	if (!map_data)
		return (exit_error(data, "Map error"), NULL);
	return (map_data);
}

void	free_textures(t_data *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->calc->texture[i])
			mlx_delete_texture(game->calc->texture[i]);
		i++;
	}
}

bool	check_path(t_data *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->calc->map[i])
	{
		j = 0;
		while (game->calc->map[i][j])
		{
			if (ft_strchr("10NSEW", game->calc->map[i][j]) == NULL
				&& game->calc->map[i][j] != ' ')
				return (exit_error(game, "Invalid character in map"), false);
			if (ft_strchr("NSWE", game->calc->map[i][j]))
			{
				if (game->calc->posX != -1)
					return (exit_error(game, "Invalid map"), false);
				game->calc->playerDir = game->calc->map[i][j];
				game->calc->posY = j + 0.5;
				game->calc->posX = i + 0.5;
			}
			j++;
		}
		i++;
	}
	if (game->calc->posX == -1)
		return (exit_error(game, "Invalid map"), false);
	return (true);
}

void	flood_fill(t_data *game, int x, int y, char **map)
{
	if (y < 0 || x < 0 || !map[y] || x >= (int)ft_strlen(map[y]))
	{
		game->map_valid = false;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == '2')
		return ;
	if (map[y][x] == ' ')
	{
		game->map_valid = false;
		return ;
	}
	map[y][x] = '2';
	flood_fill(game, x + 1, y, map);
	flood_fill(game, x - 1, y, map);
	flood_fill(game, x, y - 1, map);
	flood_fill(game, x, y + 1, map);
}

bool	parsing(t_data *game, char *path)
{
	char **map_data = NULL;
	int count = 0, i = -1, nb = 0;

	map_data = map_open(game, path, map_data);
	if (!map_data)
		return false;

	while (map_data[++i]) {
		if (map_data[i][0] == '\0')
			return (free_split(map_data), exit_error(game, "Empty line in map"), false);
		count += ft_strlen(map_data[i]);
	}

	nb = 0;
	while (map_data[nb] && map_data[nb][0] != '_') {
		char *tex_path = NULL;
		if (ft_strncmp(map_data[nb], "SO ", 3) == 0)
			tex_path = ft_strtrim(map_data[nb] + 3, " ");
		else if (ft_strncmp(map_data[nb], "EA ", 3) == 0)
			tex_path = ft_strtrim(map_data[nb] + 3, " ");
		else if (ft_strncmp(map_data[nb], "NO ", 3) == 0)
			tex_path = ft_strtrim(map_data[nb] + 3, " ");
		else if (ft_strncmp(map_data[nb], "WE ", 3) == 0)
			tex_path = ft_strtrim(map_data[nb] + 3, " ");
		if (tex_path) {
			game->calc->texture[(nb % 4)] = mlx_load_png(tex_path);
			free(tex_path);
		}
		nb++;
	}

	if (!game->calc->texture[0] || !game->calc->texture[1] ||
		!game->calc->texture[2] || !game->calc->texture[3]) {
		free_split(map_data);
		return (exit_error(game, "Error loading textures"), false);
	}

	nb++;
	while (map_data[nb] && map_data[nb][0] != '_') {
		if (map_data[nb][0] == 'F' && map_data[nb][1] == ' ') {
			game->calc->f_color = parse_rgb_line(map_data[nb] + 2);
			if (game->calc->f_color == 0) {
				ft_dprintf(2, RED" Warning : Invalid floor color, switching to default.\n" DEF_COLOR);
				game->calc->f_color = 0xFFFFFFFF;
			}
		} else if (ft_strncmp(map_data[nb], "C ", 1) == 0) {
			game->calc->c_color = parse_rgb_line(map_data[nb] + 2);
			if (game->calc->c_color == 0) {
				ft_dprintf(2, RED" Warning : Invalid ceiling color, switching to default.\n" DEF_COLOR);
				game->calc->c_color = 0xFF000000;
			}
		} else {
			free_split(map_data);
			return (exit_error(game, "Invalid map data"), false);
		}
		nb++;
	}

	game->calc->map = ft_calloc((i - nb + 1), sizeof(char *));
	if (!game->calc->map)
		return (free_split(map_data), exit_error(game, "Memory allocation for map"), false);

	i = 0;
	nb++;
	while (map_data[nb]) {
		if (map_data[nb][0] == '\0' || map_data[nb][0] == ' ')
			return (free_split(map_data), exit_error(game, "Invalid map data"), false);
		game->calc->map[i] = ft_strdup(map_data[nb]);
		if (!game->calc->map[i])
			return (free_split(map_data), exit_error(game, "Memory allocation for map line"), false);
		i++;
		nb++;
	}

	free_split(map_data);
	check_path(game);
	get_player_dir(game);
	flood_fill(game, (int)game->calc->posY, (int)game->calc->posX, game->calc->map);
	if (!game->map_valid)
		return (exit_error(game, "Invalid map"), false);
	return true;
}
