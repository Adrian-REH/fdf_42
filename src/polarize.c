/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polarize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:39:35 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/14 00:05:34 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mathmatrix.h"

void	spherize(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].axis[X] = \
		(map->radius + points[i].axis[Z]) * cos(points[i].polar[1][LONG]) * \
		sin(points[i].polar[1][LAT]);
		points[i].axis[Y] = (map->radius + points[i].axis[Z]) * \
		sin(points[i].polar[1][LONG]) * sin(points[i].polar[1][LAT]);
		points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[1][LAT]);
		i++;
	}
}

/*
*	
*	@(steps_x,steps_y) son los puntos de la circunferencia
*	@(map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y: Es para suavizar
*/
void	go_polar(t_map *map)
{
	int		i;
	float	steps_x;
	float	steps_y;

	steps_x = (M_PI * 2) / (map->limits.axis[X] - 1);
	steps_y = M_PI / (map->limits.axis[Y] - 2);
	map->radius = map->limits.axis[X] / (M_PI * 2);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[1][LONG] = (map->points[i].axis[X]) * steps_x;
		if (map->points[i].axis[Y] > 0)
			map->points[i].polar[1][LAT] = ((map->points[i].axis[Y]) + \
			(map->limits.axis[Y] / 2)) * steps_y - 0.5 * steps_y;
		else
			map->points[i].polar[1][LAT] = (map->points[i].axis[Y] + \
			(map->limits.axis[Y] / 2) - 1) * steps_y + 0.5 * steps_y;
		i++;
	}
}

void	cylindricalize(t_map *map, t_point *points)
{
	int	i;

	i = 0;
	while (i < map->len)
	{
		points[i].axis[X] = (map->radius + points[i].axis[Z]) * \
		cos(points[i].polar[0][LONG]);
		points[i].axis[Z] = (map->radius + points[i].axis[Z]) * \
		sin(points[i].polar[0][LONG]) + points[i].axis[Z];
		i++;
	}
}

void	go_cylindrical(t_map *map)
{
	int		i;
	float	angle_step;

	map->radius = map->limits.axis[X] / (M_PI * 2);
	angle_step = 2 * M_PI / (map->limits.axis[X] - 1);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[0][LONG] = -(map->points[i].axis[X]) * angle_step;
		map->points[i].polar[0][LAT] = map->radius;
		i++;
	}
}

void	go_cube(t_map *map)
{
	int		i;
	float	angle_step;

	map->radius = map->limits.axis[X] / (M_PI * 2);
	angle_step = 2 * M_PI / (map->limits.axis[X] - 1);
	i = 0;
	while (i < map->len)
	{
		map->points[i].polar[0][LONG] = i * angle_step;
		map->points[i].polar[0][LAT] = map->radius;
		i++;
	}
}
