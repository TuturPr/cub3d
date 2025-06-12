/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:20:03 by arthur            #+#    #+#             */
/*   Updated: 2025/06/12 15:55:22 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_hook(t_data *data)
{
	mlx_loop_hook(data->mlx, _key_hook, data);
	return (EXIT_SUCCESS);
}

static void	free_all(t_data *data)
{
	mlx_terminate(data->mlx);
	free_textures(data);
	free_split(data->calc->map);
	free(data->calc);
	free(data);
}


static void	ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_dprintf(STDERR_FILENO, "Usage: %s <map.cub>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	data = malloc(sizeof(t_data));
	data->calc = ft_calloc(1, sizeof(t_calc_values));
	data->mlx = mlx_init(SCREENHEIGHT, SCREENWIDTH, "cub3d", true);
	if (!data->mlx)
		ft_error();
	data->img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
		ft_error();
	init_values(data);
	parsing(data, argv[1]);
	ray_render_game(data, data->img);
	init_hook(data);
	mlx_loop(data->mlx);
	free_all(data);
	return (EXIT_SUCCESS);
}
