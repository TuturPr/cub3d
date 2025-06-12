/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:56:20 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 16:58:19 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static char	*setup_joined(char *maps, char *line)
{
	char	*joined;

	joined = ft_strjoin(maps, line);
	free(maps);
	free(line);
	if (!joined)
		return (NULL);
	return (joined);
}

static char	*read_map_lines(int fd, t_data *data)
{
	char	*line;
	char	*maps;
	char	*temp;

	maps = ft_strdup("");
	if (!maps)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		return (free(maps), exit_error(data, "Map file is empty"), NULL);
	while (line)
	{
		if (line[0] == '\n')
		{
			temp = ft_strjoin(line, "_\n");
			free(line);
			line = temp;
		}
		maps = setup_joined(maps, line);
		line = get_next_line(fd);
	}
	return (maps);
}

char	**map_open(t_data *data, char *path, char **map_data)
{
	int		fd_map;
	char	*maps;

	fd_map = open_map(data, path);
	maps = read_map_lines(fd_map, data);
	close(fd_map);
	if (!maps)
		return (NULL);
	map_data = ft_split(maps, '\n');
	free(maps);
	if (!map_data)
		return (exit_error(data, "Map error"), NULL);
	return (map_data);
}

bool	check_empty_lines(char **map_data, t_data *game)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		if (map_data[i][0] == '\0')
		{
			free_split(map_data);
			return (exit_error(game, "Empty line in map"), false);
		}
		i++;
	}
	return (true);
}
