/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:55:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/05/24 16:44:03 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern int g_map[MAPHEIGHT][MAPWIDTH];

static void prepare_render(t_calc_values *calc)
{
	calc->rayDirX = calc->dirX + calc->planeX * calc->cameraX;
	calc->rayDirY = calc->dirY + calc->planeY * calc->cameraX;
	calc->mapX = (int)calc->posX;
	calc->mapY = (int)calc->posY;
	if (calc->rayDirX == 0)
		calc->deltaDistX = 1e30;
	else
		calc->deltaDistX = fabs(1 / calc->rayDirX);
	if (calc->rayDirY == 0)
		calc->deltaDistY = 1e30;
	else
		calc->deltaDistY = fabs(1 / calc->rayDirY);
	calc->hit = 0;
}

static void dda(t_calc_values *calc)
{
	while (calc->hit == 0)
	{
		if (calc->sideDistX < calc->sideDistY)
		{
			calc->sideDistX += calc->deltaDistX;
          	calc->mapX += calc->stepX;
          	calc->side = 0;
		}
		else
		{
			calc->sideDistY += calc->deltaDistY;
         	calc->mapY += calc->stepY;
          	calc->side = 1;
		}
		if(g_map[calc->mapY][calc->mapX] != 0) calc->hit = 1;
	}
}

static void draw_line(t_calc_values *calc, mlx_image_t* img, int x)
{
	if (calc->drawStart < 0)
		calc->drawStart = 0;
    if (calc->drawEnd >= (int)img->height)
		calc->drawEnd = img->height - 1;
	int y = calc->drawStart;
	uint32_t color = 0x00ff00ff; // rose si bug

	if (g_map[calc->mapY][calc->mapX] == 1)
		color = (calc->side == 0) ? 0xff0000ff : 0x0000ffff; // rouge ou bleu

	while (y < calc->drawEnd)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}

void ray_render_game(t_calc_values *calc, mlx_image_t* img)
{
	int x;

	x = 0;
	while (x < SCREENWIDTH)
	{
		calc->cameraX = (2 * x / (double)SCREENWIDTH)- 1;
		prepare_render(calc);
		ray_calc_side(calc);
		dda(calc);
		ray_calc_walls(calc);
		draw_line(calc, img, x);
		x++;
	}
}
