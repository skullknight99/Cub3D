/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:51:43 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 13:10:18 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	rgb_atoi(char *str, t_cub *cub)
{
	int	i;
	int	flag;
	int	nbr;

	i = 0;
	flag = 1;
	nbr = 0;
	while (ft_isspace(str[i]) || str[i] == 'C' || str[i] == 'F')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error("Error: wrong rgb value\n", cub);
		if (str[i] == '0' && str[i + 1] && flag)
			ft_error("Error: wrong rgb value\n", cub);
		flag = 0;
		nbr = (nbr * 10) + (str[i] - '0');
		if (nbr > 255)
			ft_error("Error: wrong rgb value\n", cub);
		i++;
	}
	return (nbr);
}

static int	get_color(int r, int g, int b)
{
	return (65536 * r + 256 * g + b);
}

static int	get_rgb_value(char *line, t_cub *cub)
{
	int		i;
	char	**colors;
	int		rgb;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	colors = ft_split(line, ',');
	if (!colors || td_arr_size(colors) != 3)
		ft_error("Wrong rgb value\n", cub);
	rgb = get_color(rgb_atoi(colors[0], cub),
			rgb_atoi(colors[1], cub),
			rgb_atoi(colors[2], cub));
	free_td(colors);
	cub->flags++;
	return (rgb);
}

void	get_colors(t_cub *cub, char *line)
{
	if (!ft_strncmp(line, "F ", 2) && cub->map.floor == -1)
		cub->map.floor = get_rgb_value(line + 2, cub);
	else if (!ft_strncmp(line, "C ", 2) && cub->map.ceiling == -1)
		cub->map.ceiling = get_rgb_value(line + 2, cub);
	else
		ft_error("ERROR: in the identifiers\n", cub);
}
