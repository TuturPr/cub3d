/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:59:30 by aperceva          #+#    #+#             */
/*   Updated: 2025/05/24 16:14:11 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	front_move(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	move = false;
	if(g_map[(int)(calc->posX + calc->dirX * SPEED)][(int)calc->posY] == false)
	{
		calc->posX += calc->dirX * SPEED;
		move = true;
	}
    if(g_map[(int)calc->posX][(int)(calc->posY + calc->dirY * SPEED)] == false)
	{
		calc->posY += calc->dirY * SPEED;
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
	/* if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move |= back_move();
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move |= left_move();
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move |= right_move(); */
	return (move);
}

static void	_key_hook(void *param)
{
	t_data *data;
	bool	move;

	move = false;
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_T))
		ray_render_game(data->calc, data->img);
	//move |= rotate_key(data->mlx);
	move |= move_key(data);
	if (move)
		ray_render_game(data->calc, data->img);
}

bool	init_hook(t_data *data)
{
	mlx_loop_hook(data->mlx, _key_hook, data);
	//mlx_close_hook(data->mlx, exit_, data-mlx);
	return (EXIT_SUCCESS);
}
