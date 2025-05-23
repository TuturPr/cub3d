/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:40:06 by aperceva          #+#    #+#             */
/*   Updated: 2025/05/23 18:56:44 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_calc_values(calc_values *calc)
{
	calc->posX = 5;
	calc->posY = 6;
	calc->dirX = -1;
	calc->dirY = 0;
	calc->planeX = 0;
	calc->planeY = 0.66;
}

void ray_calc_side(calc_values *calc)
{
	if (calc->rayDirX < 0)
	{
		calc->stepX = -1;
		calc->sideDistX = (calc->posX - calc->mapX) * calc->deltaDistX;
	}
	else
	{
		calc->stepX = 1;
		calc->sideDistX = (calc->mapX + 1.0 - calc->posX) * calc->deltaDistX;
	}
	if (calc->rayDirY < 0)
	{
		calc->stepY = -1;
		calc->sideDistY = (calc->posY - calc->mapY) * calc->deltaDistY;
	}
	else
	{
		calc->stepY = 1;
		calc->sideDistY = (calc->mapY + 1.0 - calc->posY) * calc->deltaDistY;
	}
}

void ray_calc_walls(calc_values *calc)
{
	if(calc->side == 0)
		calc->perpWallDist = (calc->sideDistX - calc->deltaDistX);
    else          calc->perpWallDist = (calc->sideDistY - calc->deltaDistY);

	calc->lineHeight = (int)(SCREENHEIGHT / calc->perpWallDist);
	calc->drawStart = -calc->lineHeight / 2 + SCREENHEIGHT / 2;
	if (calc->drawStart < 0) calc->drawStart = 0;
	calc->drawEnd = calc->lineHeight / 2 + SCREENHEIGHT / 2;
	if (calc->drawEnd >= SCREENHEIGHT) calc->drawEnd = SCREENHEIGHT - 1;
}
