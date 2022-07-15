/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:23:31 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 13:15:55 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_td(char **arr)
{
	int	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
		arr = NULL;
	}
}

void	init_mlx_vars(t_cub *cub)
{
	cub->mlx.mlx = mlx_init();
	cub->mlx.win = mlx_new_window(cub->mlx.mlx, WIDTH, HEIGHT, "cub3D");
	cub->mlx.img = mlx_new_image(cub->mlx.mlx, WIDTH, HEIGHT);
	cub->mlx.addr = mlx_get_data_addr(cub->mlx.img, &(cub->mlx.bpp),
			&(cub->mlx.line_l), &(cub->mlx.end));
}

void	free_struct(t_cub *cub)
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

void	ft_error(char *s, t_cub *cub)
{
	free_struct(cub);
	ft_putstr_fd(s, 2);
	exit(EXIT_FAILURE);
}
