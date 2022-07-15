/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:20:44 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 13:20:45 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	left_rotation(t_cub *cub, double old_dir_x, double old_plane_x)
{
	cub->plr.dir.x = cub->plr.dir.x * cos(-ROT_SPD)
		- cub->plr.dir.y * sin(-ROT_SPD);
	cub->plr.dir.y = old_dir_x * sin(-ROT_SPD)
		+ cub->plr.dir.y * cos(-ROT_SPD);
	cub->ray.plane.x = cub->ray.plane.x * cos(-ROT_SPD)
		- cub->ray.plane.y * sin(-ROT_SPD);
	cub->ray.plane.y = old_plane_x * sin(-ROT_SPD)
		+ cub->ray.plane.y * cos(-ROT_SPD);
}

void	right_rotation(t_cub *cub, double old_dir_x, double old_plane_x)
{
	cub->plr.dir.x = cub->plr.dir.x * cos(ROT_SPD)
		- cub->plr.dir.y * sin(ROT_SPD);
	cub->plr.dir.y = old_dir_x * sin(ROT_SPD) + cub->plr.dir.y * cos(ROT_SPD);
	cub->ray.plane.x = cub->ray.plane.x * cos(ROT_SPD)
		- cub->ray.plane.y * sin(ROT_SPD);
	cub->ray.plane.y = old_plane_x * sin(ROT_SPD)
		+ cub->ray.plane.y * cos(ROT_SPD);
}
