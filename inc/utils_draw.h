/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:53:56 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:18:58 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_DRAW_H
# define UTILS_DRAW_H
# include "../inc/main.h"

void	dot_util(t_meta *meta, t_point pixel, t_point point, int coord);
void	draw_dot(t_meta *meta, t_point point, int radius);
void	paint_stars(t_meta *meta);

#endif