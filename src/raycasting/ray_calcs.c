/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:40:06 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/11 16:20:08 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_calc_values(t_data *data)
{
	t_calc_values *calc;

	calc = data->calc;
	calc->posX = -1;
	calc->posY = -1;
	calc->mouseY = SCREENHEIGHT / 2;
	data->calc->f_color = 0xFFFFFFFF;
  	data->calc->c_color = 0xFF000000;
}

void ray_calc_side(t_calc_values *calc)
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

void ray_calc_walls(t_calc_values *calc)
{
	int offset = -calc->offsetY;

	// Distance perpendiculaire au mur
	if (calc->side == 0 || calc->side == 2)
		calc->perpWallDist = (calc->sideDistX - calc->deltaDistX);
	else
		calc->perpWallDist = (calc->sideDistY - calc->deltaDistY);

	// Hauteur de la ligne
	calc->lineHeight = (int)(SCREENHEIGHT / calc->perpWallDist);

	// Position verticale de départ/fin
	calc->drawStart = (-calc->lineHeight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	calc->drawEnd = (calc->lineHeight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawEnd >= SCREENHEIGHT)
		calc->drawEnd = SCREENHEIGHT - 1;

	// Point exact d'impact du rayon sur le mur
	if (calc->side == 0 || calc->side == 2) // mur vertical (axe X)
		calc->wallX = calc->posY + calc->perpWallDist * calc->rayDirY;
	else // mur horizontal (axe Y)
		calc->wallX = calc->posX + calc->perpWallDist * calc->rayDirX;
	calc->wallX -= floor(calc->wallX); // partie fractionnaire

	// Coordonnée x de la texture
	calc->tex_x = (int)(calc->wallX * TEXWIDTH);
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= TEXWIDTH)
		calc->tex_x = TEXWIDTH - 1;

	// Inversion selon la direction du rayon
	if ((calc->side == 0 && calc->rayDirX > 0) || (calc->side == 1 && calc->rayDirY < 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
	if ((calc->side == 2 && calc->rayDirX < 0) || (calc->side == 3 && calc->rayDirY > 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
}

