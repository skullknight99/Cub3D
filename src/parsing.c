/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acmaghou <acmaghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:40:40 by acmaghou          #+#    #+#             */
/*   Updated: 2022/07/14 18:17:42 by acmaghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_and_check_map_line(t_cub *cub, char *line)
{
	char	**tmp;
	int		i;

	i = -1;
	cub->map.height++;
	tmp = malloc(sizeof(char *) * (cub->map.height + 1));
	if (!tmp)
		ft_error("allocation failed", cub);
	while (++i < (cub->map.height - 1))
		tmp[i] = ft_strdup(cub->map.map[i]);
	tmp[cub->map.height] = NULL;
	if (check_line(line))
		tmp[i] = ft_strdup(line);
	else
	{
		tmp[i] = NULL;
		free_td(tmp);
		ft_error("invalid map\n", cub);
	}
	if (cub->map.height > 1)
		free_td(cub->map.map);
	cub->map.map = tmp;
}

static void	identify_line(t_cub *cub, char *gline)
{
	int		i;
	char	*line;

	i = 0;
	line = ft_strtrim(gline, "\n");
	free(gline);
	if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
		|| line[0] == 'E')
		get_textures(cub, line);
	else if (line[0] == 'F' || line[0] == 'C')
		get_colors(cub, line);
	else if (cub->flags == 6)
		get_and_check_map_line(cub, line);
	free(line);
}

static void	readfile(t_cub *cub, int fd)
{
	char	*line;
	
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		identify_line(cub, line);
	}
	close(fd);
	if (cub->flags != 6)
		ft_error("failed to get the identifiers\n", cub);
	find_player(cub);
	check_map_errors(cub);
}

void	parsing(t_cub *cub, char *map, int ac)
{
	int	fd;

	if (ac != 2)
		ft_error("Wrong num of arguments\n", cub);
	if (ft_strncmp(map + ft_strlen(map) - 4, ".cub", 4))
		ft_error("The map should be .cub\n", cub);
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error("can't open map file\n", cub);
	readfile(cub, fd);
}