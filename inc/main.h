/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:07:10 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:18:27 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_C
# define MAIN_C
# include "../lib/minilibx-linux/mlx.h"
# include "../inc/mathmatrix.h"
# include "../inc/utils_color.h"
# include "../inc/projection.h"
# include "../inc/utils_peripheral.h"
# include "../inc/peripheral.h"
# include "../inc/maps.h"
# include "../inc/draw.h"
# include "../inc/color.h"
# include "../inc/positions.h"
# include "../lib/ft_printf/ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <math.h>
# include <X11/keysymdef.h>
# define MAP_SIZE 6

int	draw_line(t_meta *meta, t_point start, t_point end);
int	draw_map(t_meta *meta);
#endif