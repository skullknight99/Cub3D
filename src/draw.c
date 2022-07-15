/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:02:59 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 14:10:27 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_pixel(t_cub *cub, int i, int j, int color)
{
	int	y;
	int	x;

	y = HEIGHT * 0.005 * i;
	while (y < HEIGHT * 0.005 * (i + 1))
	{
		x = HEIGHT * 0.005 * j;
		while (x < HEIGHT * 0.005 * (j + 1))
		{
			mlx_put_pixel(cub, x + 20, y + 5, color);
			x++;
		}
		y++;
	}
}

static void	draw_minimap(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '1')
				draw_pixel(cub, i, j, 0x288BA8);
			j++;
		}
		i++;
	}
	draw_pixel(cub, cub->plr.pos.y, cub->plr.pos.x, 0xFFCE30);
}

static void	draw_floor_ceiling(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			if (y < HEIGHT / 2)
				mlx_put_pixel(cub, x, y, cub->map.ceiling);
			else
				mlx_put_pixel(cub, x, y, cub->map.floor);
		}
	}
}

int	draw(t_cub *cub)
{
	int	x;

	x = -1;
	draw_floor_ceiling(cub);
	while (++x < WIDTH)
	{
		ray_calcs(cub, x);
		dda(cub);
		wall_height(cub);
		textures(cub, x);
	}
	draw_minimap(cub);
	mlx_put_image_to_window(cub->mlx.mlx, cub->mlx.win, cub->mlx.img, 0, 0);
	return (21);
}
