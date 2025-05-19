/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:20:03 by arthur            #+#    #+#             */
/*   Updated: 2025/05/19 17:08:03 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480

static void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}
int main(void)
{
	mlx_t* mlx = mlx_init(screenWidth, screenHeight, "cub3d", true);
	if (!mlx)
		ft_error();
	mlx_image_t* img = mlx_new_image(mlx, 640, 480);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
			ft_error();
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

