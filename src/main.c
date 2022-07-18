/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eassamer <eassamer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 14:15:22 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/18 10:25:08 by eassamer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	init_struct(&cub);
	init_mlx_vars(&cub);
	parsing(&cub, av[1], ac);
	mlx_hook(cub.mlx.win, 2, 0, key_click, &cub);
	mlx_hook(cub.mlx.win, 17, 0, exit_free, &cub);
	mlx_loop_hook(cub.mlx.mlx, draw, &cub);
	mlx_loop(cub.mlx.mlx);
}
