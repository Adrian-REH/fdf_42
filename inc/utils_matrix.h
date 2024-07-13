/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_matrix.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:46:58 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:19:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MATRIX_H
# define UTILS_MATRIX_H
# include "../inc/data.h"
# include "../inc/mathmatrix.h"

void	matrix_init(float (*matrix)[3]);
void	translate_and_project_map(t_point *points, t_map map, t_map base, \
float proyect_matrix[3][3]);
t_point	mul_mat(float matrix[3][3], t_point point);
void	angle(float *ang, float value);
void	matrix_init(float (*matrix)[3]);

#endif