/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:23:45 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/utils_map.h"

void	softened(t_point *proyect, float divisor, int len)
{
	int	i;

	i = 0;
	(void)divisor;
	while (i < len)
	{
		proyect[i].axis[Z] = proyect[i].axis[Z] / divisor;
		i++;
	}
}

char	*fast_read(int fd)
{
	static int	byte_read = BLOCK_READ;
	static int	total_bytes = 0;
	char		*buffer;
	char		*temp;
	char		*map;

	buffer = malloc(BLOCK_READ * sizeof(char));
	if (buffer == NULL)
		exit(1);
	map = ft_strdup("");
	while (byte_read == BLOCK_READ)
	{
		ft_bzero (buffer, BLOCK_READ);
		byte_read = read(fd, buffer, BLOCK_READ);
		temp = map;
		map = ft_strjoin(map, buffer);
		total_bytes += byte_read;
		free(temp);
	}
	byte_read = BLOCK_READ;
	total_bytes = 0;
	return (free(buffer), map);
}

/* 
*	This function copy len points of the array from src to dst
*/
void	copy_map(t_point *src, t_point *dst, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
}

void	dbl_free(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

int	load_points(char *line, t_map *map, int numline, int fin)
{
	char		**splited;
	int			i;
	static int	point_index = 0;

	if (fin == 1)
		return ((point_index = 0), 0);
	splited = ((i = 0), ft_split(line, ' '));
	while (splited[i] && splited[i][0] != '\n')
	{
		if (!valid_point(&splited[i][0]))
			exit(1);
		map->points[point_index].axis[Z] = ft_atoi(&splited[i][0]);
		map->points[point_index].axis[X] = i - map->limits.axis[X] / 2;
		map->points[point_index].axis[Y] = numline - map->limits.axis[Y] / 2;
		map->points[point_index].paint = 1;
		map->points[point_index].color = DEFAULT_COLOR;
		map->points[point_index].hex_color = has_hexcolors (splited[i]);
		if (map->limits.axis[Z] < map->points[point_index].axis[Z])
			map->limits.axis[Z] = map->points[point_index].axis[Z];
		if (map->zmin > map->points[point_index].axis[Z])
			map->zmin = map->points[point_index].axis[Z];
		point_index += ((i++), (1));
	}
	return (dbl_free(splited), i);
}
