/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 17:47:10 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/15 15:41:00 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	*get_wall_textures(t_cub *cub, char *line)
{
	int		i;
	int		x;
	int		y;
	void	*img;
	char	*adr;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (line[i] == '.' || line[i] == '/')
	{
		img = mlx_xpm_file_to_image(cub->mlx.mlx, line + i, &x, &y);
		if (!img || x != 64 || y != 64)
			ft_error("incompatible xpm file\n", cub);
		adr = mlx_get_data_addr(img, &x, &y, &i);
		cub->flags++;
		return (adr);
	}
	ft_error("wrong texture file\n", cub);
	return (NULL);
}

void	get_textures(t_cub *cub, char *line)
{
	if (!ft_strncmp(line, "NO ", 3) && !cub->map.north)
		cub->map.north = get_wall_textures(cub, line + 3);
	else if (!ft_strncmp(line, "SO ", 3) && !cub->map.south)
		cub->map.south = get_wall_textures(cub, line + 3);
	else if (!ft_strncmp(line, "WE ", 3) && !cub->map.west)
		cub->map.west = get_wall_textures(cub, line + 3);
	else if (!ft_strncmp(line, "EA ", 3) && !cub->map.east)
		cub->map.east = get_wall_textures(cub, line + 3);
	else
		ft_error("error in the textures Identifiers\n", cub);
}

void	pre_calcs(t_cub *cub)
{
	double	wall_x;

	if (cub->ray.side == 0)
		wall_x = cub->plr.pos.y + cub->ray.walldist * cub->ray.raydir.y;
	else
		wall_x = cub->plr.pos.x + cub->ray.walldist * cub->ray.raydir.x;
	wall_x -= floor(wall_x);
	cub->wall.tex_x = (int)(wall_x * 64);
	cub->wall.step = 1.0 * 64 / cub->ray.height;
	cub->wall.tex_pos = (cub->ray.start - HEIGHT / 2 + cub->ray.height / 2)
		* cub->wall.step;
}

int	texturing(t_cub *cub)
{
	if (cub->ray.side == 0)
	{
		if (cub->ray.raydir.x >= 0)
			return (((unsigned int *)(cub->map.east))
			[64 * cub->wall.tex_y + cub->wall.tex_x]);
		else
			return (((unsigned int *)(cub->map.west))
			[64 * cub->wall.tex_y + cub->wall.tex_x]);
	}
	else
	{
		if (cub->ray.raydir.y >= 0)
			return (((unsigned int *)(cub->map.south))
			[64 * cub->wall.tex_y + cub->wall.tex_x]);
		else
			return (((unsigned int *)(cub->map.north))
			[64 * cub->wall.tex_y + cub->wall.tex_x]);
	}
}

void	textures(t_cub *cub, int x)
{
	int				y;
	unsigned int	color;

	pre_calcs(cub);
	y = cub->ray.start;
	while (y <= cub->ray.end)
	{
		cub->wall.tex_y = (int)cub->wall.tex_pos & (64 - 1);
		cub->wall.tex_pos += cub->wall.step;
		color = texturing(cub);
		mlx_put_pixel(cub, x, y, color);
		y++;
	}
}
