/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:55:14 by aperceva          #+#    #+#             */
/*   Updated: 2025/06/17 15:31:21 by aperceva         ###   ########.fr       */
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
# define R_SPEED 0.05
# define INVALID_F "Warning : Invalid F color, using default."
# define INVALID_C "Warning : Invalid C color, using default."
# define MA_E "Memory allocation error for map"

typedef struct s_calc_values
{
	double			wallx;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			raydirx;
	double			raydiry;
	double			camerax;
	double			deltadistx;
	double			deltadisty;
	double			sidedistx;
	double			sidedisty;
	double			perpwalldist;
	double			tex_x;
	double			step;
	double			texpos;
	double			sensitivity;
	double			rotspeed;
	char			**map;
	int				tex_y;
	int				offsety;
	int				mousex;
	int				mousey;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	char			playerdir;
	mlx_texture_t	*texture[4];
	uint32_t		f_color;
	uint32_t		c_color;
}	t_calc_values;

typedef struct s_data
{
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_calc_values	*calc;
	bool			map_valid;
}	t_data;

void			init_values(t_data *data);
void			ray_render_game(t_data *data, mlx_image_t *img);
void			ray_calc_side(t_calc_values *calc);
void			ray_calc_walls(t_calc_values *calc);
void			parse_map(char *path, t_data *data);
bool			parsing(t_data *game, char *path);
void			get_player_dir(t_data *data);
void			exit_error(t_data *data, char *message);
void			free_split(char **split);
void			free_textures(t_data *game);
uint32_t		get_texture_color(mlx_texture_t *texture, int pos);
bool			move_key(t_data *data);
void			_key_hook(void *param);
bool			rotate_key(t_data *data);
bool			mouse_rotate(t_data *data, int mouseDeltaX);
bool			check_path(t_data *game);
void			flood_fill(t_data *game, int x, int y, char **map);
unsigned int	parse_rgb_line(const char *line);
char			**map_open(t_data *data, char *path, char **map_data);
bool			check_empty_lines(char **map_data, t_data *game);
bool			is_ber_file(const char *argv);
void			set_color(t_data *game, char type);

#endif
