/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:55:09 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/17 15:30:53 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_textures(t_data *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game->calc->texture[i])
			mlx_delete_texture(game->calc->texture[i]);
		i++;
	}
}

void	set_color(t_data *game, char type)
{
	if (type == 'F' && game->calc->f_color == 0)
	{
		ft_dprintf(2, RED"%s\n"DEF_COLOR, INVALID_F);
		game->calc->f_color = 0xFFFFFF00;
	}
	else if (type == 'C' && game->calc->c_color == 0)
	{
		ft_dprintf(2, RED"%s\n"DEF_COLOR, INVALID_C);
		game->calc->c_color = 0xFF000000;
	}
}
