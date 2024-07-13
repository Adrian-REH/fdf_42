/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:01:36 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:16:59 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H
# include "main.h"

void	map_ini_colors(t_map *map);
int		has_hexcolors(char *line);
void	colorize(t_map *map);
int		gradient(int startcolor, int endcolor, int len, int pix);
void	set_color(char *buffer, int endian, int color, int alpha);
int		get_color(t_meta *meta, int color);
void	load_color(int max, int min, t_point *point, t_colors	colors);

#endif