/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:56:05 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/projection.h"

/*
*	Set the values to draw ISOMETRIC view
*/
void	isometric(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len)
	{
		map[i].ang[X] = 30;
		map[i].ang[Y] = 330;
		map[i].ang[Z] = 30;
		map[i].brange = 0;
		i++;
	}
}

/* 
*	This function draw the proyection of map->points acording all
*	the modifiers (x,y,z, scale..). If fit = 1, will caculate the 
*	scale needed to fit the screen.
*/
void	orto_proyection(t_point *points, t_point *proyection, int len)
{
	int		i;
	float	proyect_matrix[3][3];

	matrix_init(proyect_matrix);
	proyect_matrix[0][0] = 1;
	proyect_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		proyection[i] = mul_mat(proyect_matrix, points[i]);
		i++;
	}
}
