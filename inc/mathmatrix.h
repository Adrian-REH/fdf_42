/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathmatrix.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 13:04:43 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/17 11:25:12 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHMATRIX_H
# define MATHMATRIX_H
# define LAT 0
# define LONG 1
# include "../inc/utils_matrix.h"
# include "../inc/data.h"
# include "../lib/libft/libft.h"

t_point	mul_mat(float matrix[3][3], t_point point);
void	rotate_x_base(t_point *points, t_map map, t_map base, float ang);
void	rotate_y_base(t_point *points, t_map map, t_map base, float ang);
void	rotate_z_base(t_point *points, t_map map, t_map base, float ang);
void	orto_proyection(t_point *points, t_point *proyection, int len);
void	traslate_o(t_point *points, t_point move, t_map map);
void	traslate(t_point *points, t_point move, t_map map);
void	scale(t_point *points, t_map map);
void	angle(float *ang, float value);
void	matrix_init(float (*matrix)[3]);
void	spherize(t_map *map, t_point *points);
void	go_polar(t_map *map);
void	cylindricalize(t_map *map, t_point *points);
void	go_cylindrical(t_map *map);
void	isometric(t_map *map);

#endif