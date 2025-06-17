/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:52:22 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/17 14:13:38 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#include <stdbool.h>

static int	parse_component(const char **line)
{
	int	val;
	int	digits;

	val = 0;
	digits = 0;
	while (**line >= '0' && **line <= '9')
	{
		val = val * 10 + (**line - '0');
		(*line)++;
		digits++;
		if (digits > 3)
			return (-1);
	}
	if (val < 0 || val > 255)
		return (-1);
	return (val);
}

unsigned int	parse_rgb_line(const char *line)
{
	int	r;
	int	g;
	int	b;

	r = parse_component(&line);
	if (r == -1 || *line != ',')
		return (0);
	line++;
	g = parse_component(&line);
	if (g == -1 || *line != ',')
		return (0);
	line++;
	b = parse_component(&line);
	if (b == -1 || (*line != '\0' && *line != '\n'))
		return (0);
	return ((r << 24) | (g << 16) | (b << 8) | 255);
}
