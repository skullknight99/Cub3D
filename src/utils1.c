/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:10:32 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 13:18:26 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_put_pixel(t_cub *cub, int x, int y, int color)
{
	int	i;

	i = (x * cub->mlx.bpp / 8) + (y * cub->mlx.line_l);
	cub->mlx.addr[i] = (char)(color);
	cub->mlx.addr[i + 1] = (char)(color / 256);
	cub->mlx.addr[i + 2] = (char)(color / 65536);
}

int	td_arr_size(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

void	init_struct(t_cub *cub)
{
	cub->map.map = NULL;
	cub->map.height = 0;
	cub->map.north = NULL;
	cub->map.south = NULL;
	cub->map.west = NULL;
	cub->map.east = NULL;
	cub->map.floor = -1;
	cub->map.ceiling = -1;
	cub->plr.pos.x = 0;
	cub->plr.pos.y = 0;
	cub->plr.dir.x = 0;
	cub->plr.dir.y = 0;
	cub->ray.plane.x = 0;
	cub->ray.plane.y = 0;
	cub->flags = 0;
}

void	free_structure(t_cub *cub)
{
	if (cub->map.map)
		free_td(cub->map.map);
	if (cub->map.north)
		free(cub->map.north);
	if (cub->map.south)
		free(cub->map.south);
	if (cub->map.west)
		free(cub->map.west);
	if (cub->map.east)
		free(cub->map.east);
	if (cub->mlx.img)
		mlx_destroy_image(cub->mlx.mlx, cub->mlx.img);
	if (cub->mlx.win)
		mlx_destroy_window(cub->mlx.mlx, cub->mlx.win);
}

int	exit_free(t_cub *cub)
{
	free_structure(cub);
	exit(0);
}
