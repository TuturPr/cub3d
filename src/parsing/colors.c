/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:52:22 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 16:52:42 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
