/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:04:37 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 23:06:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H
# include "../inc/main.h"
# include "../inc/valid.h"
# include "../inc/utils_map.h"

void	copy_map(t_point *src, t_point *dst, int len);
void	dbl_free(char **ptr);
void	map_get_points(t_map *map);
void	map_ini(t_map *map, int total);
void	load_map(t_meta *map, char *path);
void	parse_map(t_meta *meta, t_point *proyect, int n_map);
#endif