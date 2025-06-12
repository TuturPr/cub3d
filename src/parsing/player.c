/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 16:05:24 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 17:15:42 by aperceva         ###   ########.fr       */
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
	data->calc->dirx = -1;
	data->calc->diry = 0;
	data->calc->planex = 0;
	data->calc->planey = 0.66;
}

static void	east(t_data *data)
{
	data->calc->dirx = 0;
	data->calc->diry = 1;
	data->calc->planex = 0.66;
	data->calc->planey = 0;
}

static void	south(t_data *data)
{
	data->calc->dirx = 1;
	data->calc->diry = 0;
	data->calc->planex = 0;
	data->calc->planey = -0.66;
}

static void	west(t_data *data)
{
	data->calc->dirx = 0;
	data->calc->diry = -1;
	data->calc->planex = -0.66;
	data->calc->planey = 0;
}

void	get_player_dir(t_data *data)
{
	if (data->calc->playerdir == 'N')
		north(data);
	else if (data->calc->playerdir == 'E')
		east(data);
	else if (data->calc->playerdir == 'S')
		south(data);
	else if (data->calc->playerdir == 'W')
		west(data);
	else
	{
		exit_error(data, "Invalid player direction");
		exit(EXIT_FAILURE);
	}
}
