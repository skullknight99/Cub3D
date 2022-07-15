/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:48:33 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 12:55:46 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_player_direction(t_cub *cub, int player, double i, double j)
{
	cub->plr.pos.x = j;
	cub->plr.pos.y = i;
	if (player == 'N')
	{
		cub->plr.dir.y = -1;
		cub->ray.plane.x = 0.66;
	}
	else if (player == 'S')
	{
		cub->plr.dir.y = 1;
		cub->ray.plane.x = -0.66;
	}
	else if (player == 'W')
	{
		cub->plr.dir.x = -1;
		cub->ray.plane.y = -0.66;
	}
	else if (player == 'E')
	{
		cub->plr.dir.x = 1;
		cub->ray.plane.y = 0.66;
	}
}

void	find_player(t_cub *cub)
{
	int		i;
	int		j;
	int		count;
	int		plr;

	count = 0;
	i = -1;
	while (cub->map.map[++i])
	{
		j = -1;
		while (cub->map.map[i][++j])
		{
			plr = cub->map.map[i][j];
			if (plr == 'N' || plr == 'S' || plr == 'W' || plr == 'E')
			{
				count++;
				if (count == 2)
					ft_error("Error: multiple players\n", cub);
				get_player_direction(cub, plr, i, j);
				cub->map.map[i][j] = '0';
			}
		}
	}
	if (!count)
		ft_error("Error: player not found\n", cub);
}
