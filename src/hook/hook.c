/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:59:30 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:14:27 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move_check(t_data *data, bool move)
{
	if (move)
		ray_render_game(data, data->img);
}

static void	handle_key(t_data *data)
{
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_T))
		ray_render_game(data, data->img);
}

void	_key_hook(void *param)
{
	t_data	*data;
	bool	move;

	move = false;
	data = param;
	mlx_get_mouse_pos(data->mlx, &data->calc->mousex, &data->calc->mousey);
	if (data->calc->mousex != SCREENWIDTH / 2
		|| data->calc->mousey != SCREENHEIGHT / 2)
	{
		if (data->calc->mousex != SCREENWIDTH / 2)
			move |= mouse_rotate(data, data->calc->mousex - SCREENWIDTH / 2);
		if (data->calc->mousey != SCREENHEIGHT / 2)
			data->calc->offsety += data->calc->mousey - SCREENHEIGHT / 2;
		if (data->calc->offsety < -SCREENHEIGHT)
			data->calc->offsety = -SCREENHEIGHT;
		else if (data->calc->offsety > SCREENHEIGHT)
			data->calc->offsety = SCREENHEIGHT;
	}
	mlx_set_mouse_pos(data->mlx, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	handle_key(data);
	move |= rotate_key(data);
	move_check(data, move);
	move |= move_key(data);
	move_check(data, move);
}
