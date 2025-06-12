/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:43:38 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:10:52 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	front_move(t_data *data)
{
	t_calc_values	*calc;
	bool			move;

	calc = data->calc;
	move = false;
	if (data->calc->map[(int)(calc->posx + calc->dirx * SPEED)] \
		[(int)calc->posy] != '1')
	{
		calc->posx += calc->dirx * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posx] \
		[(int)(calc->posy + calc->diry * SPEED)] != '1')
	{
		calc->posy += calc->diry * SPEED;
		move = true;
	}
	return (move);
}

static bool	back_move(t_data *data)
{
	t_calc_values	*calc;
	bool			move;

	calc = data->calc;
	move = false;
	if (data->calc->map[(int)(calc->posx - calc->dirx * SPEED)] \
		[(int)calc->posy] != '1')
	{
		calc->posx -= calc->dirx * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posx] \
		[(int)(calc->posy - calc->diry * SPEED)] != '1')
	{
		calc->posy -= calc->diry * SPEED;
		move = true;
	}
	return (move);
}

static bool	left_move(t_data *data)
{
	t_calc_values	*calc;
	bool			move;

	calc = data->calc;
	move = false;
	if (data->calc->map[(int)(calc->posx - calc->diry * SPEED)] \
		[(int)calc->posy] != '1')
	{
		calc->posx -= calc->diry * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posx] \
		[(int)(calc->posy + calc->dirx * SPEED)] != '1')
	{
		calc->posy += calc->dirx * SPEED;
		move = true;
	}
	return (move);
}

static bool	right_move(t_data *data)
{
	t_calc_values	*calc;
	bool			move;

	calc = data->calc;
	move = false;
	if (data->calc->map[(int)(calc->posx + calc->diry * SPEED)] \
		[(int)calc->posy] != '1')
	{
		calc->posx += calc->diry * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posx] \
		[(int)(calc->posy - calc->dirx * SPEED)] != '1')
	{
		calc->posy -= calc->dirx * SPEED;
		move = true;
	}
	return (move);
}

bool	move_key(t_data	*data)
{
	bool	move;

	move = false;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move |= front_move(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move |= back_move(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move |= left_move(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move |= right_move(data);
	return (move);
}
