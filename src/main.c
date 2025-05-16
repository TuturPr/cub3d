/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:20:03 by arthur            #+#    #+#             */
/*   Updated: 2025/05/16 17:32:13 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Written by Bruh

#include <stdio.h>
#include "MLX42.h"

#define WIDTH 1280
#define HEIGHT 720

static void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "cub3d", true);
	if (!mlx)
		ft_error();

	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 0, 0) < 0))
		ft_error();

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
