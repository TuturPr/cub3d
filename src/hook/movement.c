/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 14:43:38 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 14:52:53 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	front_move(t_data *data)
{
	t_calc_values	*calc;
	bool			move;

	calc = data->calc;
	move = false;
	if (data->calc->map[(int)(calc->posX + calc->dirX * SPEED)] \
		[(int)calc->posY] != '1')
	{
		calc->posX += calc->dirX * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posX] \
		[(int)(calc->posY + calc->dirY * SPEED)] != '1')
	{
		calc->posY += calc->dirY * SPEED;
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
	if (data->calc->map[(int)(calc->posX - calc->dirX * SPEED)] \
		[(int)calc->posY] != '1')
	{
		calc->posX -= calc->dirX * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posX] \
		[(int)(calc->posY - calc->dirY * SPEED)] != '1')
	{
		calc->posY -= calc->dirY * SPEED;
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
	if (data->calc->map[(int)(calc->posX - calc->dirY * SPEED)] \
		[(int)calc->posY] != '1')
	{
		calc->posX -= calc->dirY * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posX] \
		[(int)(calc->posY + calc->dirX * SPEED)] != '1')
	{
		calc->posY += calc->dirX * SPEED;
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
	if (data->calc->map[(int)(calc->posX + calc->dirY * SPEED)] \
		[(int)calc->posY] != '1')
	{
		calc->posX += calc->dirY * SPEED;
		move = true;
	}
	if (data->calc->map[(int)calc->posX] \
		[(int)(calc->posY - calc->dirX * SPEED)] != '1')
	{
		calc->posY -= calc->dirX * SPEED;
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
