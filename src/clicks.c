/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clicks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:14:04 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 13:14:54 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	l_r_rotation(int key, t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->plr.dir.x;
	old_plane_x = cub->ray.plane.x;
	if (key == LEFT)
		left_rotation(cub, old_dir_x, old_plane_x);
	if (key == RIGHT)
		right_rotation(cub, old_dir_x, old_plane_x);
}

static void	click_a_d(int key, t_cub *cub)
{
	if (key == A)
	{
		if (cub->map.map[(int)(cub->plr.pos.y)]
			[(int)(cub->plr.pos.x - cub->ray.plane.x * MV_SPD)] == '0')
			cub->plr.pos.x -= cub->ray.plane.x * MV_SPD;
		if (cub->map.map[(int)(cub->plr.pos.y - cub->ray.plane.y * MV_SPD)]
			[(int)(cub->plr.pos.x)] == '0')
			cub->plr.pos.y -= cub->ray.plane.y * MV_SPD;
	}
	if (key == D)
	{
		if (cub->map.map[(int)(cub->plr.pos.y)]
			[(int)(cub->plr.pos.x + cub->ray.plane.x * MV_SPD)] == '0')
			cub->plr.pos.x += cub->ray.plane.x * MV_SPD;
		if (cub->map.map[(int)(cub->plr.pos.y + cub->ray.plane.y * MV_SPD)]
			[(int)(cub->plr.pos.x)] == '0')
			cub->plr.pos.y += cub->ray.plane.y * MV_SPD;
	}
}

static void	click_w_s(int key, t_cub *cub)
{
	if (key == W)
	{
		if (cub->map.map[(int)(cub->plr.pos.y)]
			[(int)(cub->plr.pos.x + cub->plr.dir.x * MV_SPD)] == '0')
			cub->plr.pos.x += cub->plr.dir.x * MV_SPD;
		if (cub->map.map[(int)(cub->plr.pos.y + cub->plr.dir.y * MV_SPD)]
			[(int)(cub->plr.pos.x)] == '0')
			cub->plr.pos.y += cub->plr.dir.y * MV_SPD;
	}
	if (key == S)
	{
		if (cub->map.map[(int)(cub->plr.pos.y)]
			[(int)(cub->plr.pos.x - cub->plr.dir.x * MV_SPD)] == '0')
			cub->plr.pos.x -= cub->plr.dir.x * MV_SPD;
		if (cub->map.map[(int)(cub->plr.pos.y - cub->plr.dir.y * MV_SPD)]
			[(int)(cub->plr.pos.x)] == '0')
			cub->plr.pos.y -= cub->plr.dir.y * MV_SPD;
	}
}

int	key_click(int key, t_cub *cub)
{
	if (key == ESC)
		exit_free(cub);
	else if (key == W || key == S)
		click_w_s(key, cub);
	else if (key == A || key == D)
		click_a_d(key, cub);
	else if (key == LEFT || key == RIGHT)
		l_r_rotation(key, cub);
	return (1);
}
