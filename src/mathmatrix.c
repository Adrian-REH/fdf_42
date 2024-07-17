/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:06:31 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/17 11:27:48 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/../inc/mathmatrix.h"

/*
*   Calculate len "points" of the array with the "ang" rotation in X axis
*   and store in "proyection" array.
*/
void	rotate_x_base(t_point *points, t_map map, t_map base, float ang)
{
	float	rad;
	float	proyect_matrix[3][3];

	rad = (ang) * (3.14159265358979323846) / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[1][2] = -sin(rad);
	proyect_matrix[2][1] = sin(rad);
	proyect_matrix[2][2] = cos(rad);
	translate_and_project_map(points, map, base, proyect_matrix);
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Y axis
*   and store in "proyection" array.
*/
void	rotate_y_base(t_point *points, t_map map, t_map base, float ang)
{
	float	rad;
	float	proyect_matrix[3][3];

	rad = (ang) * (M_PI) / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][2] = sin(rad);
	proyect_matrix[1][1] = 1;
	proyect_matrix[2][0] = -sin(rad);
	proyect_matrix[2][2] = cos(rad);
	translate_and_project_map(points, map, base, proyect_matrix);
}

/*
*   Calculate len "points" of the array with the "ang" rotation in Z axis
*   and store in "proyection" array.
*/
void	rotate_z_base(t_point *points, t_map map, t_map base, float ang)
{
	float	rad;
	float	proyect_matrix[3][3];

	rad = (ang) * (M_PI) / 180;
	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = cos(rad);
	proyect_matrix[0][1] = -sin(rad);
	proyect_matrix[1][0] = sin(rad);
	proyect_matrix[1][1] = cos(rad);
	proyect_matrix[2][2] = 1;
	translate_and_project_map(points, map, base, proyect_matrix);
}

void	traslate(t_point *points, t_point move, t_map map)
{
	int	i;

	i = 0;
	while (i < map.len)
	{
		points[i].axis[X] = points[i].axis[X] + move.axis[X];
		points[i].axis[Y] = points[i].axis[Y] + move.axis[Y];
		points[i].axis[Z] = (points[i].axis[Z] + move.axis[Z]);
		i++;
	}
}

/*
*	Iterates all the points and multiply by scale
*/
void	scale(t_point *points, t_map map)
{
	int		i;
	t_point	center_move;
	t_point	center;

	i = 0;
	center_move.axis[X] = map.source.axis[X] - \
	(((WINX - MENU_WIDTH) / 2) + MENU_WIDTH);
	center_move.axis[Y] = map.source.axis[Y] - (WINY / 2);
	center_move.axis[Z] = 0;
	center.axis[X] = -map.source.axis[X] + \
	(((WINX - MENU_WIDTH) / 2) + MENU_WIDTH);
	center.axis[Y] = -map.source.axis[Y] + (WINY / 2);
	center.axis[Z] = 0;
	traslate(points, center_move, map);
	while (i < map.len)
	{
		points[i].axis[X] = points[i].axis[X] * map.scale;
		points[i].axis[Y] = points[i].axis[Y] * map.scale;
		points[i].axis[Z] = points[i].axis[Z] * map.scale;
		i++;
	}
	traslate(points, center, map);
}
