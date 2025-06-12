/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:58:55 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/12 15:51:53 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	exit_error(t_data *data, char *message)
{
	ft_dprintf(2, RED"Error: %s\n"DEF_COLOR, message);
	free_textures(data);
	free_split(data->calc->map);
	if (data->mlx)
	{
		if (data->img)
			mlx_delete_image(data->mlx, data->img);
		mlx_terminate(data->mlx);
	}
	if (data->calc)
		free(data->calc);
	if (data)
		free(data);
	exit(1);
}
