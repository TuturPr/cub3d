/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 17:46:27 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/17 16:01:12 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static inline char	*get_texture_path(t_data *game, char *line)
{
	if (!ft_strncmp(line, "SO ", 3))
		game->calc->texture[0] = mlx_load_png(ft_strtrim(line + 3, " "));
	else if (!ft_strncmp(line, "EA ", 3))
		game->calc->texture[1] = mlx_load_png(ft_strtrim(line + 3, " "));
	else if (!ft_strncmp(line, "NO ", 3))
		game->calc->texture[2] = mlx_load_png(ft_strtrim(line + 3, " "));
	else if (!ft_strncmp(line, "WE ", 3))
		game->calc->texture[3] = mlx_load_png(ft_strtrim(line + 3, " "));
	return (NULL);
}

static int	parse_textures(char **map_data, t_data *game)
{
	int		nb;

	nb = 0;
	while (map_data[nb] && map_data[nb][0] == '_')
		nb++;
	while (map_data[nb] && map_data[nb][0] != '_')
	{
		get_texture_path(game, map_data[nb]);
		nb++;
	}
	if (!game->calc->texture[0] || !game->calc->texture[1]
		|| !game->calc->texture[2] || !game->calc->texture[3])
		return (free_split(map_data), \
		exit_error(game, "Error loading textures"), -1);
	return (nb + 1);
}

static int	parse_colors(char **map_data, t_data *game, int nb)
{
	while (map_data[nb] && map_data[nb][0] == '_')
		nb++;
	while (map_data[nb] && map_data[nb][0] != '_')
	{
		if (!ft_strncmp(map_data[nb], "F ", 2))
		{
			game->calc->f_color = parse_rgb_line(map_data[nb] + 2);
			set_color(game, 'F');
		}
		else if (!ft_strncmp(map_data[nb], "C ", 2))
		{
			game->calc->c_color = parse_rgb_line(map_data[nb] + 2);
			set_color(game, 'C');
		}
		else
			return (free_split(map_data), exit_error(game, "Invalid map"), -1);
		nb++;
	}
	return (nb + 1);
}

static bool	copy_map(char **map_data, t_data *game, int nb)
{
	int	i;
	int	map_size;

	map_size = 0;
	while (map_data[nb] && map_data[nb][0] == '_')
		nb++;
	while (map_data[nb + map_size])
		map_size++;
	game->calc->map = ft_calloc((map_size + 1), sizeof(char *));
	if (!game->calc->map)
		return (free_split(map_data), \
		exit_error(game, "Memory allocation for map"), false);
	i = 0;
	while (map_data[nb])
	{
		if (map_data[nb][0] == '\0' || map_data[nb][0] == ' ')
			return (free_split(map_data), \
			exit_error(game, "Invalid map data"), false);
		game->calc->map[i] = ft_strdup(map_data[nb]);
		if (!game->calc->map[i])
			return (free_split(map_data), exit_error(game, MA_E), false);
		i++;
		nb++;
	}
	return (true);
}

bool	parsing(t_data *game, char *path)
{
	char	**map_data;
	int		nb;

	map_data = map_open(game, path, NULL);
	if (!map_data)
		return (false);
	if (!check_empty_lines(map_data, game))
		return (false);
	nb = parse_textures(map_data, game);
	if (nb == -1)
		return (false);
	nb = parse_colors(map_data, game, nb);
	if (nb == -1)
		return (false);
	if (!copy_map(map_data, game, nb))
		return (false);
	free_split(map_data);
	check_path(game);
	get_player_dir(game);
	flood_fill(game, (int)game->calc->posy, \
	(int)game->calc->posx, game->calc->map);
	if (!game->map_valid)
		return (exit_error(game, "Invalid map"), false);
	return (true);
}
