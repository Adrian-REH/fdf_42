/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:46:24 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/utils_matrix.h"

void	matrix_init(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	angle(float *ang, float value)
{
	*ang += value;
	if (*ang < 0)
		*ang = 360 + *ang;
	if (*ang >= 360)
		*ang = *ang - 360;
}

/*
*   Multiply a 3 points coordinate "point" by Matrix [3][3]
*   and return the result.
*/
t_point	mul_mat(float matrix[3][3], t_point point)
{
	int		i;
	int		k;
	t_point	result;

	result = point;
	i = 0;
	while (i < 3)
	{
		result.axis[i] = 0;
		result.color = point.color;
		k = 0;
		while (k < 3)
		{
			result.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	return (result);
}

//UTILS
void	translate_and_project_map(t_point *points, t_map map, t_map base, \
float proyect_matrix[3][3])
{
	t_point	center_move;
	t_point	center;
	int		i;

	i = 0;
	center_move.axis[X] = map.source.axis[X] - base.source.axis[X];
	center_move.axis[Y] = map.source.axis[Y] - base.source.axis[Y];
	center_move.axis[Z] = 0;
	center.axis[X] = -map.source.axis[X] + base.source.axis[X];
	center.axis[Y] = -map.source.axis[Y] + base.source.axis[Y];
	center.axis[Z] = 0;
	traslate(points, center_move, map);
	while (i < map.len)
	{
		points[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
	traslate(points, center, map);
}
