/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:05:30 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/maps.h"

void	map_get_points(t_map *map)
{
	int			i;
	char		*line;
	char		*last_line;
	static int	num_points = 0;
	static int	num_line = 0;

	last_line = map->memory;
	line = NULL;
	i = 0;
	map->points = ft_calloc (map->len, sizeof(t_point));
	while (++i)
	{
		if (map->memory[i] == '\n' || map->memory[i] == '\0')
		{
			free (line);
			line = ft_substr(last_line, 0, &map->memory[i] - last_line);
			last_line = &map->memory[i + 1];
			num_points += load_points(line, map, num_line++, 0);
			if (map->memory[i] == '\0')
				break ;
		}
	}
	(load_points(line, map, num_line, 1), free (line));
	num_line = 0;
	num_points = 0;
}

void	map_ini(t_map *map, int total)
{
	if (total)
	{
		map->len = ((map->zmin = 0), (0));
		map->limits.axis[X] = 0;
		map->limits.axis[Y] = 0;
		map->limits.axis[Z] = 0;
	}
	map->b_lines = 1;
	map->b_dots = 0;
	map->b_pluslines = 0;
	map->scale = ((map->b_geo = 0), (map->b_cil = 0), (1));
	map->visible = 1;
	map->min_scale = 1;
	map->source.axis[X] = (((WINX - MENU_WIDTH) / 2) + MENU_WIDTH);
	map->source.axis[Y] = (WINY / 2);
	map->source.axis[Z] = 0;
	map->b_stars = ((map->b_shadow = 1), (map->zdivisor = 1), (0));
	map->brange = 0;
	map->ang[Y] = ((map->ang[X] = 0), (map->ang[Z] = 0), 0);
	map_ini_colors(map);
}

/* 
*	This function determinates the max values x, y, z of the map
*	and terminate if the maps has different line sizes.
*/
void	map_size(t_map *map)
{
	static int	i = -1;
	static int	num_elems = 0;	

	while (map->memory[++i])
	{
		if (map->memory[i] == '\n' && map->memory[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->memory[i]) && \
			(map->memory[i + 1] == ' ' || map->memory[i + 1] == '\n' || \
			map->memory[i + 1] == '\0'))
			num_elems++;
		if (map->memory[i] == '\n')
		{
			map->limits.axis[Y]++;
			if (map->limits.axis[X] != 0 && (map->limits.axis[X] != num_elems))
				exit(1);
			else
				map->limits.axis[X] = num_elems;
			num_elems = 0;
		}
	}
	if (num_elems > 0 && (map->limits.axis[X] != num_elems))
		exit(1);
	i = ((map->limits.axis[Y]++), (num_elems = 0), -1);
	map->len = map->limits.axis[X] * map->limits.axis[Y];
}

void	load_map(t_meta *meta, char *path)
{
	int	fd;
	int	n_map;

	n_map = MAP_SIZE;
	map_ini(&meta->map[0], 1);
	fd = open(path, O_RDONLY);
	if (fd < 2)
		exit(1);
	meta->map[0].memory = fast_read(fd);
	close (fd);
	map_size(&meta->map[0]);
	map_get_points(&meta->map[0]);
	colorize(&meta->map[0]);
	go_polar(&meta->map[0]);
	go_cylindrical(&meta->map[0]);
	free(meta->map[0].memory);
	meta->n_maps = n_map;
	while (n_map-- > 0)
		meta->map[n_map] = meta->map[0];
}

/*
*	Call all the functions to modify the points in the space
*/
void	parse_map(t_meta *meta, t_point *proyect, int n_map)
{
	if (meta->b_soft)
		softened(proyect, 100, meta->map[n_map].len);
	if (meta->map[n_map].b_geo && !meta->map[n_map].b_cil)
		spherize(&meta->map[n_map], proyect);
	if (!meta->map[n_map].b_geo && meta->map[n_map].b_cil)
		cylindricalize(&meta->map[n_map], proyect);
	rotate_x(proyect, meta->map[n_map], meta->map[0]);
	rotate_y(proyect, meta->map[n_map], meta->map[0]);
	rotate_z(proyect, meta->map[n_map], meta->map[0]);
	scale (proyect, meta->map[n_map]);
	traslate(proyect, meta->map[n_map].source, meta->map[n_map]);
}