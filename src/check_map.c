/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 18:15:46 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/14 18:15:56 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_top_nd_bottom(t_cub *cub, int i, int j)
{
	if (cub->map.map[i - 1][j] != '1' && cub->map.map[i - 1][j] != '0')
		ft_error("Error: invalid map", cub);
	if (cub->map.map[i + 1][j] != '1' && cub->map.map[i + 1][j] != '0')
		ft_error("Error: invalid map", cub);
}

void	check_left_nd_right(t_cub *cub, int i, int j)
{
	if (cub->map.map[i][j - 1] != '1' && cub->map.map[i][j - 1] != '0')
		ft_error("Error: invalid map", cub);
	if (cub->map.map[i][j + 1] != '1' && cub->map.map[i][j + 1] != '0')
		ft_error("Error: invalid map", cub);
}

void	check_map_errors(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (cub->map.map[i])
	{
		j = 0;
		while (cub->map.map[i][j])
		{
			if (cub->map.map[i][j] == '0')
			{
				if (i == 0 || j == 0)
					ft_error("Error: invalid map", cub);
				if (!(cub->map.map[i - 1][j]) || !(cub->map.map[i][j - 1])
					|| !(cub->map.map[i + 1][j]) || !(cub->map.map[i][j + 1]))
					ft_error("Error: invalid map", cub);
				check_top_nd_bottom(cub, i, j);
				check_left_nd_right(cub, i, j);
			}
			j++;
		}
		i++;
	}
}

int	check_line(char *line)
{
	int	n;

	n = 0;
	while (line[n])
	{
		if (line[n] != '1' && line[n] != '0' && line[n] != 'N'
			&& line[n] != 'S' && line[n] != 'W' && line[n] != 'E'
			&& !ft_isspace(line[n]))
			return (0);
		n++;
	}
	return (1);
}
