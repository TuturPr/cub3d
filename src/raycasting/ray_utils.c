/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:14:49 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 14:14:54 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

uint32_t	get_texture_color(mlx_texture_t *texture, int pos)
{
	uint32_t	color;

	pos *= 4;
	color = (uint32_t)texture->pixels[pos] << 24;
	color |= (uint32_t)texture->pixels[pos + 1] << 16;
	color |= (uint32_t)texture->pixels[pos + 2] << 8;
	color |= 0xFF;
	return (color);
}
