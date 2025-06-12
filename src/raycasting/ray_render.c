/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:55:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:31 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	prepare_render(t_calc_values *calc)
{
	calc->raydirx = calc->dirx + calc->planex * calc->camerax;
	calc->raydiry = calc->diry + calc->planey * calc->camerax;
	calc->mapx = (int)calc->posx;
	calc->mapy = (int)calc->posy;
	if (calc->raydirx == 0)
		calc->deltadistx = 1e30;
	else
		calc->deltadistx = fabs(1 / calc->raydirx);
	if (calc->raydiry == 0)
		calc->deltadisty = 1e30;
	else
		calc->deltadisty = fabs(1 / calc->raydiry);
	calc->hit = 0;
}

static void	dda(t_calc_values *calc)
{
	while (calc->hit == 0)
	{
		if (calc->sidedistx < calc->sidedisty)
		{
			calc->sidedistx += calc->deltadistx;
			calc->mapx += calc->stepx;
			if (calc->stepx < 0)
				calc->side = 0;
			else
				calc->side = 2;
		}
		else
		{
			calc->sidedisty += calc->deltadisty;
			calc->mapy += calc->stepy;
			if (calc->stepy < 0)
				calc->side = 1;
			else
				calc->side = 3;
		}
		if (calc->map[calc->mapx][calc->mapy] == '1')
			calc->hit = 1;
	}
}

static void	init(t_data *data, mlx_image_t *img)
{
	int				offset;
	t_calc_values	*calc;

	calc = data->calc;
	offset = -calc->offsety;
	calc->step = TEXHEIGHT / (double)calc->lineheight;
	calc->texpos = (calc->drawstart - SCREENHEIGHT / 2 \
		+ calc->lineheight / 2 - offset) * calc->step;
	if (calc->drawstart < 0)
		calc->drawstart = 0;
	if (calc->drawend >= (int)img->height)
		calc->drawend = img->height - 1;
}

static void	draw_line(t_data *data, mlx_image_t *img, int x)
{
	int				y;
	t_calc_values	*calc;

	calc = data->calc;
	init(data, img);
	y = 0;
	while (y++ < calc->drawstart)
		if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
			mlx_put_pixel(img, x, y, calc->c_color);
	y = calc->drawstart;
	while (y++ < calc->drawend)
	{
		calc->tex_y = (int)calc->texpos % TEXHEIGHT;
		if (calc->tex_y < 0)
			calc->tex_y += TEXHEIGHT;
		calc->texpos += calc->step;
		mlx_put_pixel(img, x, y,
			get_texture_color(calc->texture[calc->side],
				TEXWIDTH * calc->tex_y + calc->tex_x));
	}
	y = calc->drawend;
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
		calc->camerax = (2 * x / (double)SCREENWIDTH) - 1;
		prepare_render(calc);
		ray_calc_side(calc);
		dda(calc);
		ray_calc_walls(calc);
		draw_line(data, img, x);
		x++;
	}
}
