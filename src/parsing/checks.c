/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:54:19 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:42 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_ber_file(const char *argv)
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

bool	check_tile(t_data *game, int i, int j)
{
	char	c;

	c = game->calc->map[i][j];
	if (!ft_strchr("10NSEW", c) && c != ' ')
		return (exit_error(game, "Invalid character in map"), false);
	if (ft_strchr("NSWE", c))
	{
		if (game->calc->posx != -1)
			return (exit_error(game, "Invalid map"), false);
		game->calc->playerdir = c;
		game->calc->posy = j + 0.5;
		game->calc->posx = i + 0.5;
	}
	return (true);
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
			if (!check_tile(game, i, j))
				return (false);
			j++;
		}
		i++;
	}
	if (game->calc->posx == -1)
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
