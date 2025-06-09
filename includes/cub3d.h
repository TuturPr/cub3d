/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:14 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/09 17:29:05 by aperceva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include "MLX42.h"
# include <math.h>

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define SPEED 0.11
# define R_SPEED 0.04

typedef struct s_calc_values{
	double wallX;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double rayDirX;
	double rayDirY;
	double cameraX;
	double deltaDistX;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	double tex_x;
	int offsetY;
	int mouseX;
	int mouseY;
	int lineHeight;
	int drawStart;
	int drawEnd;
	int mapX;
	int mapY;
	int stepX;
	int stepY;
	int hit;
	int side;
	mlx_texture_t *texture[4];
} t_calc_values;

typedef struct s_data {
	mlx_t *mlx;
	mlx_image_t *img;
	t_calc_values *calc;
	mlx_texture_t *otis;
	bool m_control;
} t_data;

extern int g_map[MAPHEIGHT][MAPWIDTH];

bool	init_hook(t_data *data);
void init_calc_values(t_data *data);
void ray_render_game(t_calc_values *calc, mlx_image_t* img);
void ray_calc_side(t_calc_values *calc);
void ray_calc_walls(t_calc_values *calc);

#endif
