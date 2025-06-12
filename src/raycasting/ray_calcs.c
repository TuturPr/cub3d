/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:40:06 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:31 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_values(t_data *data)
{
	t_calc_values	*calc;

	mlx_set_window_limit(data->mlx, SCREENWIDTH, \
		SCREENHEIGHT, SCREENWIDTH, SCREENHEIGHT);
	mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
	mlx_set_mouse_pos(data->mlx, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	calc = data->calc;
	calc->posx = -1;
	calc->posy = -1;
	calc->mousey = SCREENHEIGHT / 2;
	data->map_valid = true;
}

void	ray_calc_side(t_calc_values *calc)
{
	if (calc->raydirx < 0)
	{
		calc->stepx = -1;
		calc->sidedistx = (calc->posx - calc->mapx) * calc->deltadistx;
	}
	else
	{
		calc->stepx = 1;
		calc->sidedistx = (calc->mapx + 1.0 - calc->posx) * calc->deltadistx;
	}
	if (calc->raydiry < 0)
	{
		calc->stepy = -1;
		calc->sidedisty = (calc->posy - calc->mapy) * calc->deltadisty;
	}
	else
	{
		calc->stepy = 1;
		calc->sidedisty = (calc->mapy + 1.0 - calc->posy) * calc->deltadisty;
	}
}

static void	ray_calc_end(t_calc_values *calc)
{
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= TEXWIDTH)
		calc->tex_x = TEXWIDTH - 1;
	if ((calc->side == 0 && calc->raydirx > 0)
		|| (calc->side == 1 && calc->raydiry < 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
	if ((calc->side == 2 && calc->raydirx < 0)
		|| (calc->side == 3 && calc->raydiry > 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
}

void	ray_calc_walls(t_calc_values *calc)
{
	int	offset;

	offset = -calc->offsety;
	if (calc->side == 0 || calc->side == 2)
		calc->perpwalldist = (calc->sidedistx - calc->deltadistx);
	else
		calc->perpwalldist = (calc->sidedisty - calc->deltadisty);
	calc->lineheight = (int)(SCREENHEIGHT / calc->perpwalldist);
	calc->drawstart = (-calc->lineheight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawstart < 0)
		calc->drawstart = 0;
	calc->drawend = (calc->lineheight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawend >= SCREENHEIGHT)
		calc->drawend = SCREENHEIGHT - 1;
	if (calc->side == 0 || calc->side == 2)
		calc->wallx = calc->posy + calc->perpwalldist * calc->raydiry;
	else
		calc->wallx = calc->posx + calc->perpwalldist * calc->raydirx;
	calc->wallx -= floor(calc->wallx);
	calc->tex_x = (int)(calc->wallx * TEXWIDTH);
	ray_calc_end(calc);
}
