/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:46:52 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:11:35 by aperceva         ###   ########.fr       */
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
	oldxirx = calc->posy;
	calc->dirx = calc->dirx * cos(-R_SPEED) - calc->diry * sin(-R_SPEED);
	calc->diry = oldxirx * sin(-R_SPEED) + calc->diry * cos(-R_SPEED);
	oldplanex = calc->planex;
	calc->planex = calc->planex * cos(-R_SPEED) - calc->planey * sin(-R_SPEED);
	calc->planey = oldplanex * sin(-R_SPEED) + calc->planey * cos(-R_SPEED);
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
	oldxirx = calc->dirx;
	calc->dirx = calc->dirx * cos(data->calc->rotspeed) \
		- calc->diry * sin(data->calc->rotspeed);
	calc->diry = oldxirx * sin(data->calc->rotspeed) \
		+ calc->diry * cos(data->calc->rotspeed);
	oldplanex = calc->planex;
	calc->planex = calc->planex * cos(data->calc->rotspeed) \
		- calc->planey * sin(data->calc->rotspeed);
	calc->planey = oldplanex * sin(data->calc->rotspeed) \
		+ calc->planey * cos(data->calc->rotspeed);
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
	oldxirx = calc->dirx;
	calc->dirx = calc->dirx * cos(R_SPEED) - calc->diry * sin(R_SPEED);
	calc->diry = oldxirx * sin(R_SPEED) + calc->diry * cos(R_SPEED);
	oldplanex = calc->planex;
	calc->planex = calc->planex * cos(R_SPEED) - calc->planey * sin(R_SPEED);
	calc->planey = oldplanex * sin(R_SPEED) + calc->planey * cos(R_SPEED);
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
