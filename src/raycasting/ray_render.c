/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:55:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 14:43:00 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	prepare_render(t_calc_values *calc)
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

static void	dda(t_calc_values *calc)
{
	while (calc->hit == 0)
	{
		if (calc->sideDistX < calc->sideDistY)
		{
			calc->sideDistX += calc->deltaDistX;
			calc->mapX += calc->stepX;
			if (calc->stepX < 0)
				calc->side = 0;
			else
				calc->side = 2;
		}
		else
		{
			calc->sideDistY += calc->deltaDistY;
			calc->mapY += calc->stepY;
			if (calc->stepY < 0)
				calc->side = 1;
			else
				calc->side = 3;
		}
		if (calc->map[calc->mapX][calc->mapY] == '1')
			calc->hit = 1;
	}
}

static void	init(t_data *data, mlx_image_t *img)
{
	int				offset;
	t_calc_values	*calc;

	calc = data->calc;
	offset = -calc->offsetY;
	calc->step = TEXHEIGHT / (double)calc->lineHeight;
	calc->texpos = (calc->drawStart - SCREENHEIGHT / 2 \
		+ calc->lineHeight / 2 - offset) * calc->step;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	if (calc->drawEnd >= (int)img->height)
		calc->drawEnd = img->height - 1;
}

static void	draw_line(t_data *data, mlx_image_t *img, int x)
{
	int				y;
	t_calc_values	*calc;

	calc = data->calc;
	init(data, img);
	y = 0;
	while (y++ < calc->drawStart)
		if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
			mlx_put_pixel(img, x, y, calc->c_color);
	y = calc->drawStart;
	while (y++ < calc->drawEnd)
	{
		calc->tex_y = (int)calc->texpos % TEXHEIGHT;
		if (calc->tex_y < 0)
			calc->tex_y += TEXHEIGHT;
		calc->texpos += calc->step;
		mlx_put_pixel(img, x, y,
			get_texture_color(calc->texture[calc->side],
				TEXWIDTH * calc->tex_y + calc->tex_x));
	}
	y = calc->drawEnd;
	while (y++ < (int)img->height)
		if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
			mlx_put_pixel(img, x, y, calc->f_color);
}

void	ray_render_game(t_data *data, mlx_image_t *img)
{
	int				x;
	t_calc_values	*calc;

	x = 0;
	calc = data->calc;
	while (x < SCREENWIDTH)
	{
		calc->cameraX = (2 * x / (double)SCREENWIDTH) - 1;
		prepare_render(calc);
		ray_calc_side(calc);
		dda(calc);
		ray_calc_walls(calc);
		draw_line(data, img, x);
		x++;
	}
}
