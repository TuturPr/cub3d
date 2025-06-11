/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:46:27 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/11 16:14:37 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <string.h>

unsigned int parse_rgb_line(const char *line) {
    int i = 0, j = 0;
    int values[3] = {0, 0, 0};

    while (line[i] && j < 3) {
        if (line[i] >= '0' && line[i] <= '9') {
            values[j] = values[j] * 10 + (line[i] - '0');
        } else if (line[i] == ',') {
            j++;
            if (j >= 3)
                return 0;
        } else if (line[i] != '\n' && line[i] != '\r') {
            return 0;
        }
        i++;
    }
    if (j != 2)
        return 0;
    for (int k = 0; k < 3; k++) {
        if (values[k] < 0) values[k] = 0;
        if (values[k] > 255) values[k] = 255;
    }

    return (values[0] << 24) | (values[1] << 16) | (values[2] << 8) | 255;
}


static bool	is_ber_file(const char *argv)
{
	char	*extension;

	extension = ft_strrchr(argv, '/');
	if (extension == NULL)
		extension = (char *)argv;
	extension = ft_strrchr(extension, '.');
	if (extension && strcmp(extension, ".cub") == 0)
		return (true);
	return (false);
}

int	open_map(char *path)
{
	int	fd;

	if (strcmp(path, "0") == 0)
		return (0);
	if (!is_ber_file(path))
		return (perror("Invalid file extension"), -1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (perror("open map"), -1);
	return (fd);
}

static char	**map_open(
	char *path,
	char **map_data
)
{
	char	*line;
	char	*new_maps;
	int		fd_map;
	char	*maps;

	maps = "";
	fd_map = open_map(path);
	line = get_next_line(fd_map);
	if (!line)
		return (NULL);
	while (line)
	{
		if (line[0] == '\n')
			line = ft_strjoin(line, "_\n");
		new_maps = ft_strjoin(maps, line);
		if (!new_maps)
			return (close(fd_map), NULL);
		maps = new_maps;
		line = get_next_line(fd_map);
	}
	map_data = ft_split(maps, '\n');
	if (!map_data)
		return (perror("[2]map error"), close(fd_map), NULL);
	return (map_data);
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
			if (strchr("NSWE", game->calc->map[i][j]))
			{
				if (game->calc->posX != -1)
					return (perror("Multiple player position"), false);
				game->calc->playerDir = game->calc->map[i][j];
				game->calc->posY = j + 0.5;
				game->calc->posX = i + 0.5;
				printf("Player position found at: %d, %d\n", i, j);
				printf("Player is at %f, %f\n", game->calc->posX, game->calc->posY);
			}
			j++;
		}
		i++;
	}
	if (game->calc->posX == -1)
		return (perror("No player position"), false);
	return (true);
}

bool	parsing(t_data *game, char *path)
{
	char	**map_data;
	char	**map_copy;
	int		count;
	int		i;
	int		nb;

	map_data = NULL;
	map_copy = NULL;
	count = 0;
	i = -1;
	nb = 0;
	map_data = map_open(path, map_data);
	if (!map_data)
		return (false);
	printf("Map data:\n");
	while (map_data[++i])
	{
		printf("%s\n", map_data[i]);
		if (map_data[i][0] == '\0')
			return (perror("Empty line in map"), false);
		count += ft_strlen(map_data[i]);
	}
	while (map_data[nb] && map_data[nb][0] != '_')
	{
		if (ft_strncmp(map_data[nb], "SO ", 3) == 0)
			game->calc->texture[0] = mlx_load_png(ft_strtrim(map_data[nb] + 3, " "));
		else if (ft_strncmp(map_data[nb], "EA ", 3) == 0)
			game->calc->texture[1] = mlx_load_png(ft_strtrim(map_data[nb] + 3, " "));
		else if (ft_strncmp(map_data[nb], "NO ", 3) == 0)
			game->calc->texture[2] = mlx_load_png(ft_strtrim(map_data[nb] + 3, " "));
		else if (ft_strncmp(map_data[nb], "WE ", 3) == 0)
			game->calc->texture[3] = mlx_load_png(ft_strtrim(map_data[nb] + 3, " "));
		nb++;
	}
	nb++;
	while (map_data[nb] && map_data[nb][0] != '_')
	{
		if (map_data[nb][0] == 'F' && map_data[nb][1] == ' ')
			game->calc->f_color = parse_rgb_line(map_data[nb] + 2);
		else if (ft_strncmp(map_data[nb], "C ", 1) == 0)
			game->calc->c_color = parse_rgb_line(map_data[nb] + 2);
		else if (map_data[nb][0] != '\0')
			return (perror("Invalid map data"), false);
		printf("Colors are: F: %u, C: %u\n", game->calc->f_color, game->calc->c_color);
		nb++;
	}
	game->calc->map = ft_calloc((i - nb + 1), sizeof(char *));
	if (!game->calc->map)
		return (perror("Memory allocation for map"), false);
	i = 0;
	while (map_data[nb])
	{
		if (map_data[nb][0] != '_')
		{
			game->calc->map[i] = ft_strdup(map_data[nb]);
			if (!game->calc->map[i])
				return (perror("Memory allocation for map line"), false);
			i++;
		}
		nb++;
	}
	check_path(game);
	get_player_dir(game);
	return (true);
}
