/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:05:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 13:25:14 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//        x dir y  |  x plane y
// NORTH -1     0  |  0       0.66
// EAST   0     1  |  0.66    0
// SOUTH  1     0  |  0      -0.66
// WEST   0    -1  | -0.66    0

static void	north(t_data *data)
{
	data->calc->dirX = -1;
	data->calc->dirY = 0;
	data->calc->planeX = 0;
	data->calc->planeY = 0.66;
}

static void	east(t_data *data)
{
	data->calc->dirX = 0;
	data->calc->dirY = 1;
	data->calc->planeX = 0.66;
	data->calc->planeY = 0;
}

static void	south(t_data *data)
{
	data->calc->dirX = 1;
	data->calc->dirY = 0;
	data->calc->planeX = 0;
	data->calc->planeY = -0.66;
}

static void	west(t_data *data)
{
	data->calc->dirX = 0;
	data->calc->dirY = -1;
	data->calc->planeX = -0.66;
	data->calc->planeY = 0;
}

void	get_player_dir(t_data *data)
{
	if (data->calc->playerDir == 'N')
		north(data);
	else if (data->calc->playerDir == 'E')
		east(data);
	else if (data->calc->playerDir == 'S')
		south(data);
	else if (data->calc->playerDir == 'W')
		west(data);
	else
	{
		exit_error(data, "Invalid player direction");
		exit(EXIT_FAILURE);
	}
}
