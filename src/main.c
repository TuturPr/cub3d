/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:20:03 by arthur            #+#    #+#             */
/*   Updated: 2025/05/23 18:57:14 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int g_map[MAPHEIGHT][MAPWIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

static void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int main(void)
{
	calc_values *calc;
	calc = ft_calloc(1, sizeof(calc_values));
	mlx_t* mlx = mlx_init(SCREENHEIGHT, SCREENWIDTH, "cub3d", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 640, 480);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error();
	mlx_set_window_limit(mlx, 640, 480, 640, 480);
	init_calc_values(calc);
	ray_render_game(calc, img);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

