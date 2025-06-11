/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 16:20:03 by arthur            #+#    #+#             */
/*   Updated: 2025/06/11 16:19:57 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void ft_error(void)
{
	ft_dprintf(STDERR_FILENO, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    ft_dprintf(STDERR_FILENO, "Usage: %s <map.cub>\n", argv[0]);
    return (EXIT_FAILURE);
  }
  t_data *data;
  data = malloc(sizeof(t_data));
	data->calc = ft_calloc(1, sizeof(t_calc_values));
	data->mlx = mlx_init(SCREENHEIGHT, SCREENWIDTH, "cub3d", true);
	if (!data->mlx)
		ft_error();
	data->img = mlx_new_image(data->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (!data->img || (mlx_image_to_window(data->mlx, data->img, 0, 0) < 0))
			ft_error();
	mlx_set_window_limit(data->mlx, SCREENWIDTH, SCREENHEIGHT, SCREENWIDTH, SCREENHEIGHT);
  mlx_set_cursor_mode(data->mlx, MLX_MOUSE_HIDDEN);
  mlx_set_mouse_pos(data->mlx, SCREENWIDTH / 2, SCREENHEIGHT / 2);
	init_calc_values(data);
  parsing(data, argv[1]);
	ray_render_game(data->calc, data->img);
  init_hook(data);
	mlx_loop(data->mlx);
	mlx_terminate(data->mlx);
  for (int i = 0; i < 4; i++)
    mlx_delete_texture(data->calc->texture[i]);
  free(data->calc);
  free(data);
	return (EXIT_SUCCESS);
}

