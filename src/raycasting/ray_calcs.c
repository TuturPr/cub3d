/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_calcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 16:40:06 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 14:19:40 by aperceva         ###   ########.fr       */
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
	calc->posX = -1;
	calc->posY = -1;
	calc->mouseY = SCREENHEIGHT / 2;
	data->map_valid = true;
}

void	ray_calc_side(t_calc_values *calc)
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

static void	ray_calc_end(t_calc_values *calc)
{
	if (calc->tex_x < 0)
		calc->tex_x = 0;
	if (calc->tex_x >= TEXWIDTH)
		calc->tex_x = TEXWIDTH - 1;
	if ((calc->side == 0 && calc->rayDirX > 0)
		|| (calc->side == 1 && calc->rayDirY < 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
	if ((calc->side == 2 && calc->rayDirX < 0)
		|| (calc->side == 3 && calc->rayDirY > 0))
		calc->tex_x = TEXWIDTH - calc->tex_x - 1;
}

void	ray_calc_walls(t_calc_values *calc)
{
	int	offset;

	offset = -calc->offsetY;
	if (calc->side == 0 || calc->side == 2)
		calc->perpWallDist = (calc->sideDistX - calc->deltaDistX);
	else
		calc->perpWallDist = (calc->sideDistY - calc->deltaDistY);
	calc->lineHeight = (int)(SCREENHEIGHT / calc->perpWallDist);
	calc->drawStart = (-calc->lineHeight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawStart < 0)
		calc->drawStart = 0;
	calc->drawEnd = (calc->lineHeight / 2 + SCREENHEIGHT / 2) + offset;
	if (calc->drawEnd >= SCREENHEIGHT)
		calc->drawEnd = SCREENHEIGHT - 1;
	if (calc->side == 0 || calc->side == 2)
		calc->wallX = calc->posY + calc->perpWallDist * calc->rayDirY;
	else
		calc->wallX = calc->posX + calc->perpWallDist * calc->rayDirX;
	calc->wallX -= floor(calc->wallX);
	calc->tex_x = (int)(calc->wallX * TEXWIDTH);
	ray_calc_end(calc);
}
