/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:59:34 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:18:34 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# include "../inc/main.h"
# include "../inc/color.h"
# include "../inc/utils_draw.h"

int		my_putpixel(t_meta *meta, t_point pixel);
void	wire_line(t_point *point, t_meta *meta, int density, int line);
void	wired(t_meta *meta, t_point *wire, int n_map);
int		draw_line(t_meta *meta, t_point start, t_point end);
int		draw_map(t_meta *meta);
void	paint_background(t_meta *meta, int backcolor, int menucolor);
void	paint_stars(t_meta *meta);

#endif