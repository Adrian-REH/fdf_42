/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 07:53:22 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/utils_draw.h"

/*
*	Auxiliar function to draw a K
*/

void	dot_util(t_meta *meta, t_point pixel, t_point point, int coord)
{
	int	i;

	i = point.axis[X];
	while (i <= point.axis[X] + coord)
	{
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] + coord;
		my_putpixel(meta, pixel);
		pixel.axis[X] = i;
		pixel.axis[Y] = (int)point.axis[Y] - coord;
		my_putpixel(meta, pixel);
		i++;
	}
}

/*
*	This function draw a K in t_point position and with r radius
*/
void	draw_dot(t_meta *meta, t_point point, int radius)
{
	int		axis[2];
	int		change[2];
	int		radius_error;
	t_point	pixel;

	axis[X] = radius;
	axis[Y] = 0;
	change[X] = 1 - (radius << 1);
	change[Y] = 0;
	radius_error = 0;
	pixel.color = point.color;
	while (axis[X] >= axis[Y])
	{
		dot_util(meta, pixel, point, axis[Y]);
		dot_util(meta, pixel, point, axis[X]);
		axis[Y]++;
		radius_error += change[Y];
		change[Y] += 2;
		if (((radius_error << 1) + change[X]) > 0)
		{
			axis[X]--;
			radius_error += change[X];
			change[X] += 2;
		}
	}
}

void	paint_stars(t_meta *meta)
{
	int		i;
	t_point	star;
	int		lim_x[2];
	int		lim_y[2];

	if (meta->map[0].b_geo == 0)
		return ;
	lim_x[0] = meta->map[0].source.axis[X] - \
	(meta->map[0].radius * meta->map[0].scale);
	lim_x[1] = meta->map[0].source.axis[X] + \
	(meta->map[0].radius * meta->map[0].scale);
	lim_y[0] = meta->map[0].source.axis[Y] - \
	(meta->map[0].radius * meta->map[0].scale);
	lim_y[1] = meta->map[0].source.axis[Y] + \
	(meta->map[0].radius * meta->map[0].scale);
	i = 0;
	while (i < 200)
	{
		star.axis[X] = ((star.axis[Y] = rand() % WINY), (rand() % WINX));
		star.color = WHITE;
		if ((star.axis[X] < lim_x[0] || star.axis[X] > lim_x[1]) \
		|| ((star.axis[Y]) < lim_y[0] || star.axis[Y] > lim_y[1]))
			draw_dot(meta, star, 2);
		i++;
	}
}
