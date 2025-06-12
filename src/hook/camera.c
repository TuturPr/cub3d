/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:46:52 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 15:05:48 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	rotate_right(t_data *data)
{
	t_calc_values	*calc;
	bool			move;
	double			oldxirx;
	double			oldplanex;

	calc = data->calc;
	oldxirx = calc->dirX;
	calc->dirX = calc->dirX * cos(-R_SPEED) - calc->dirY * sin(-R_SPEED);
	calc->dirY = oldxirx * sin(-R_SPEED) + calc->dirY * cos(-R_SPEED);
	oldplanex = calc->planeX;
	calc->planeX = calc->planeX * cos(-R_SPEED) - calc->planeY * sin(-R_SPEED);
	calc->planeY = oldplanex * sin(-R_SPEED) + calc->planeY * cos(-R_SPEED);
	move = true;
	return (move);
}

bool	mouse_rotate(t_data *data, int mouseDeltaX)
{
	t_calc_values	*calc;
	bool			move;
	double			oldxirx;
	double			oldplanex;

	data->calc->sensitivity = 0.002;
	data->calc->rotspeed = mouseDeltaX * data->calc->sensitivity * -1;
	calc = data->calc;
	oldxirx = calc->dirX;
	calc->dirX = calc->dirX * cos(data->calc->rotspeed) \
		- calc->dirY * sin(data->calc->rotspeed);
	calc->dirY = oldxirx * sin(data->calc->rotspeed) \
		+ calc->dirY * cos(data->calc->rotspeed);
	oldplanex = calc->planeX;
	calc->planeX = calc->planeX * cos(data->calc->rotspeed) \
		- calc->planeY * sin(data->calc->rotspeed);
	calc->planeY = oldplanex * sin(data->calc->rotspeed) \
		+ calc->planeY * cos(data->calc->rotspeed);
	move = true;
	return (move);
}

static bool	rotate_left(t_data *data)
{
	t_calc_values	*calc;
	bool			move;
	double			oldxirx;
	double			oldplanex;

	calc = data->calc;
	oldxirx = calc->dirX;
	calc->dirX = calc->dirX * cos(R_SPEED) - calc->dirY * sin(R_SPEED);
	calc->dirY = oldxirx * sin(R_SPEED) + calc->dirY * cos(R_SPEED);
	oldplanex = calc->planeX;
	calc->planeX = calc->planeX * cos(R_SPEED) - calc->planeY * sin(R_SPEED);
	calc->planeY = oldplanex * sin(R_SPEED) + calc->planeY * cos(R_SPEED);
	move = true;
	return (move);
}

bool	rotate_key(t_data *data)
{
	bool	move;

	move = false;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move |= rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move |= rotate_left(data);
	return (move);
}
