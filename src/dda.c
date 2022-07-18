/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:11:39 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/18 10:26:33 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_height(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.walldist = (cub->ray.sd.x - cub->ray.dd.x);
	else
		cub->ray.walldist = (cub->ray.sd.y - cub->ray.dd.y);
	cub->ray.height = (int)(HEIGHT / cub->ray.walldist);
	cub->ray.start = (HEIGHT / 2 - cub->ray.height / 2);
	if (cub->ray.start < 0)
		cub->ray.start = 0;
	cub->ray.end = (HEIGHT / 2 + cub->ray.height / 2);
	if (cub->ray.end >= HEIGHT)
		cub->ray.end = (HEIGHT - 1);
}

void	dda(t_cub *cub)
{
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sd.x < cub->ray.sd.y)
		{
			cub->ray.sd.x += cub->ray.dd.x;
			cub->map.x += cub->ray.step_x;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sd.y += cub->ray.dd.y;
			cub->map.y += cub->ray.step_y;
			cub->ray.side = 1;
		}
		if (cub->map.map[(int)(cub->map.y)][(int)(cub->map.x)] == '1')
			cub->ray.hit = 1;
	}
}

void	ray_calcs(t_cub *cub, int x)
{
	cub->map.x = (int)(cub->plr.pos.x);
	cub->map.y = (int)(cub->plr.pos.y);
	cub->ray.camera_x = (2.0 * x / (double)(WIDTH) - 1.0);
	cub->ray.raydir.x = cub->plr.dir.x + cub->ray.plane.x * cub->ray.camera_x;
	cub->ray.raydir.y = cub->plr.dir.y + cub->ray.plane.y * cub->ray.camera_x;
	cub->ray.dd.x = fabs(1.0 / cub->ray.raydir.x);
	cub->ray.dd.y = fabs(1.0 / cub->ray.raydir.y);
	cub->ray.hit = 0;
	cub->ray.step_x = 1;
	cub->ray.step_y = 1;
	cub->ray.sd.x = (cub->map.x + 1.0 - cub->plr.pos.x) * cub->ray.dd.x;
	cub->ray.sd.y = (cub->map.y + 1.0 - cub->plr.pos.y) * cub->ray.dd.y;
	if (cub->ray.raydir.x < 0)
	{
		cub->ray.step_x = -1;
		cub->ray.sd.x = (cub->plr.pos.x - cub->map.x) * cub->ray.dd.x;
	}
	if (cub->ray.raydir.y < 0)
	{
		cub->ray.step_y = -1;
		cub->ray.sd.y = (cub->plr.pos.y - cub->map.y) * cub->ray.dd.y;
	}
}
