/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:55:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/09 16:40:35 by aperceva         ###   ########.fr       */
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
		if(g_map[calc->mapX][calc->mapY] != 0) calc->hit = 1;
	}
}

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

static void draw_line(t_calc_values *calc, mlx_image_t* img, int x)
{
	double	step;
	double	texpos;
	int		tex_y;
	int offset;
	offset = -calc->offsetY;
	step = TEXHEIGHT / (double)calc->lineHeight;
	texpos = (calc->drawStart - SCREENHEIGHT / 2 + calc->lineHeight / 2 - offset) * step;


	if (calc->drawStart < 0)
		calc->drawStart = 0;
	if (calc->drawEnd >= (int)img->height)
		calc->drawEnd = img->height - 1;

	for (int y = 0; y < calc->drawStart; y++)
		mlx_put_pixel(img, x, y, 0x000000cc);
	for (int y = calc->drawStart; y < calc->drawEnd; y++)
	{
		tex_y = (int)texpos % TEXHEIGHT;
		if (tex_y < 0)
			tex_y += TEXHEIGHT;
		texpos += step;
		if (calc->side == 0)
			mlx_put_pixel(img, x, y,
				get_texture_color(calc->texture[1],
				TEXWIDTH * tex_y + calc->tex_x));
		else
			mlx_put_pixel(img, x, y,
				get_texture_color(calc->texture[0],
				TEXWIDTH * tex_y + calc->tex_x));
	}
	for (int y = calc->drawEnd; y < (int)img->height; y++)
		mlx_put_pixel(img, x, y, 0xffffffaa);
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
