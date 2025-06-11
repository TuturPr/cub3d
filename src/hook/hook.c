/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:59:30 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/11 15:31:45 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	front_move(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	move = false;
	if(data->calc->map[(int)(calc->posX + calc->dirX * SPEED)][(int)calc->posY] != '1')
	{
		calc->posX += calc->dirX * SPEED;
		move = true;
	}
	if(data->calc->map[(int)calc->posX][(int)(calc->posY + calc->dirY * SPEED)] != '1')
	{
		calc->posY += calc->dirY * SPEED;
		move = true;
	}
	return (move);
}

static bool	back_move(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	move = false;
	if(data->calc->map[(int)(calc->posX - calc->dirX * SPEED)][(int)calc->posY] != '1')
	{
		calc->posX -= calc->dirX * SPEED;
		move = true;
	}
    if(data->calc->map[(int)calc->posX][(int)(calc->posY - calc->dirY * SPEED)] != '1')
	{
		calc->posY -= calc->dirY * SPEED;
		move = true;
	}
	return (move);
}

static bool left_move(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	move = false;
	if(data->calc->map[(int)(calc->posX - calc->dirY * SPEED)][(int)calc->posY] != '1')
	{
		calc->posX -= calc->dirY * SPEED;
		move = true;
	}
	if(data->calc->map[(int)calc->posX][(int)(calc->posY + calc->dirX * SPEED)] != '1')
	{
		calc->posY += calc->dirX * SPEED;
		move = true;
	}
	return (move);
}

static bool right_move(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	move = false;
	if(data->calc->map[(int)(calc->posX + calc->dirY * SPEED)][(int)calc->posY] != '1')
	{
		calc->posX += calc->dirY * SPEED;
		move = true;
	}
	if(data->calc->map[(int)calc->posX][(int)(calc->posY - calc->dirX * SPEED)] != '1')
	{
		calc->posY -= calc->dirX * SPEED;
		move = true;
	}
	return (move);
}

static bool rotate_right(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	double oldDirX = calc->dirX;
    calc->dirX = calc->dirX * cos(-R_SPEED) - calc->dirY * sin(-R_SPEED);
    calc->dirY = oldDirX * sin(-R_SPEED) + calc->dirY * cos(-R_SPEED);
    double oldPlaneX = calc->planeX;
    calc->planeX = calc->planeX * cos(-R_SPEED) - calc->planeY * sin(-R_SPEED);
    calc->planeY = oldPlaneX * sin(-R_SPEED) + calc->planeY * cos(-R_SPEED);
	move = true;
	return (move);
}

static bool mouse_rotate(t_data *data, int mouseDeltaX)
{
	t_calc_values	*calc;
	bool	move;
	double sensitivity = 0.002;
	double rotSpeed = mouseDeltaX * sensitivity * -1;

	calc = data->calc;
	double oldDirX = calc->dirX;
	calc->dirX = calc->dirX * cos(rotSpeed) - calc->dirY * sin(rotSpeed);
	calc->dirY = oldDirX * sin(rotSpeed) + calc->dirY * cos(rotSpeed);
	double oldPlaneX = calc->planeX;
	calc->planeX = calc->planeX * cos(rotSpeed) - calc->planeY * sin(rotSpeed);
	calc->planeY = oldPlaneX * sin(rotSpeed) + calc->planeY * cos(rotSpeed);
	move = true;
	return (move);
}

static bool rotate_left(t_data *data)
{
	t_calc_values	*calc;
	bool	move;

	calc = data->calc;
	double oldDirX = calc->dirX;
	calc->dirX = calc->dirX * cos(R_SPEED) - calc->dirY * sin(R_SPEED);
	calc->dirY = oldDirX * sin(R_SPEED) + calc->dirY * cos(R_SPEED);
	double oldPlaneX = calc->planeX;
	calc->planeX = calc->planeX * cos(R_SPEED) - calc->planeY * sin(R_SPEED);
	calc->planeY = oldPlaneX * sin(R_SPEED) + calc->planeY * cos(R_SPEED);
	move = true;
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

bool rotate_key(t_data *data)
{
	bool	move;

	move = false;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		move |= rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		move |= rotate_left(data);
	return(move);
}

static void	_key_hook(void *param)
{
	t_data *data;
	bool	move;

	move = false;
	data = param;

	mlx_get_mouse_pos(data->mlx, &data->calc->mouseX, &data->calc->mouseY);
	if (data->calc->mouseX != SCREENWIDTH / 2 || data->calc->mouseY != SCREENHEIGHT / 2)
	{
		if (data->calc->mouseX != SCREENWIDTH / 2)
			move |= mouse_rotate(data, data->calc->mouseX - SCREENWIDTH / 2);
		if (data->calc->mouseY != SCREENHEIGHT / 2)
			data->calc->offsetY += data->calc->mouseY - SCREENHEIGHT / 2;
		if (data->calc->offsetY < -SCREENHEIGHT)
			data->calc->offsetY = -SCREENHEIGHT;
		else if (data->calc->offsetY > SCREENHEIGHT)
			data->calc->offsetY = SCREENHEIGHT;
	}
	mlx_set_mouse_pos(data->mlx, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_T))
		ray_render_game(data->calc, data->img);
	move |= rotate_key(data);
	if (move)
		ray_render_game(data->calc, data->img);
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
