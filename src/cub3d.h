/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 09:15:38 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/19 16:21:04 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <math.h>
# include <string.h>
# include <fcntl.h>

# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define WIDTH 1600
# define HEIGHT 1200
# define W 13
# define A 0
# define S 1
# define D 2
# define ESC 53
# define LEFT 123
# define RIGHT 124
# define MV_SPD 0.08
# define ROT_SPD 0.05

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		end;
}			t_mlx;

typedef struct s_map
{
	char	**map;
	int		height;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	int		floor;
	int		ceiling;
	int		x;
	int		y;
}			t_map;

typedef struct s_point
{
	double	x;
	double	y;
}			t_point;

typedef struct s_player
{
	t_point	pos;
	t_point	dir;
}			t_player;

typedef struct s_ray
{
	double	camera_x;
	t_point	raydir;
	t_point	plane;
	t_point	dd;
	t_point	sd;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	double	walldist;
	int		height;
	int		start;
	int		end;
}			t_ray;

typedef struct s_tex
{
	int		tex_x;
	int		tex_y;
	double	tex_pos;
	double	step;
}			t_tex;

typedef struct s_cub
{
	t_mlx		mlx;
	t_map		map;
	t_player	plr;
	t_ray		ray;
	t_tex		wall;
	int			flags;
}				t_cub;

void	init_struct(t_cub *cub);
void	init_mlx_vars(t_cub *cub);
void	free_td(char **arr);
void	parsing(t_cub *cub, char *map, int ac);
void	free_struct(t_cub *cub);
void	ft_error(char *s, t_cub *cub);
int		td_arr_size(char **arr);
int		check_line(char *line);
void	check_map_errors(t_cub *cub);
void	check_top_nd_bottom(t_cub *cub, int i, int j);
int		key_click(int key, t_cub *cub);
int		exit_free(t_cub *cub);
void	free_structure(t_cub *cub);
void	left_rotation(t_cub *cub, double old_dir_x, double old_plane_x);
void	right_rotation(t_cub *cub, double old_dir_x, double old_plane_x);
void	mlx_put_pixel(t_cub *cub, int x, int y, int color);
int		draw(t_cub *cub);
void	find_player(t_cub *cub);
void	get_textures(t_cub *cub, char *line);
void	get_colors(t_cub *cub, char *line);
void	dda(t_cub *cub);
void	wall_height(t_cub *cub);
void	ray_calcs(t_cub *cub, int x);
void	textures(t_cub *cub, int x);

#endif