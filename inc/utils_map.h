/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:23:57 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 23:05:58 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_MAP_H
# define UTILS_MAP_H
# include "../inc/main.h"

void	softened(t_point *proyect, float divisor, int len);
char	*fast_read(int fd);
void	copy_map(t_point *src, t_point *dst, int len);
void	dbl_free(char **ptr);
int		load_points(char *line, t_map *map, int numline);

#endif