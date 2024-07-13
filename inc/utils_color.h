/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_color.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:41:49 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:18:54 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_COLOR_H
# define UTILS_COLOR_H
# include "../inc/main.h"

int		ft_round(double num);
void	map_ini_colors(t_map *map);
int		has_hexcolors(char *line);
void	colorize(t_map *map);
int		gradient(int startcolor, int endcolor, int len, int pix);

#endif