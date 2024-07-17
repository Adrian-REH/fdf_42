/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 23:55:33 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 22:32:04 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/draw.h"

int	my_putpixel(t_meta *meta, t_point pixel)
{
	int	mypixel;
	int	alpha;

	alpha = 0;
	if (pixel.axis[X] < MENU_WIDTH)
		alpha = -10;
	if (pixel.axis[X] >= WINX || pixel.axis[Y] >= WINY || \
		pixel.axis[X] < 0 || pixel.axis[Y] < 0)
		return (-1);
	mypixel = ((int)pixel.axis[Y] * WINX * 4) + ((int)pixel.axis[X] * 4);
	if (meta->bitmap.bitxpixel != 32)
		pixel.color = mlx_get_color_value(meta->vars.mlx, pixel.color);
	set_color(&meta->bitmap.buffer[mypixel], \
		meta->bitmap.endian, pixel.color, alpha);
	return (0);
}

int	draw_line(t_meta *meta, t_point start, t_point end)
{
	t_point	delta;
	t_point	pixel;
	int		pixels;
	int		len;

	delta.axis[X] = end.axis[X] - start.axis[X];
	delta.axis[Y] = end.axis[Y] - start.axis[Y];
	pixels = sqrt((delta.axis[X] * delta.axis[X]) + \
			(delta.axis[Y] * delta.axis[Y]));
	len = pixels;
	delta.axis[X] /= pixels;
	delta.axis[Y] /= pixels;
	pixel.axis[X] = start.axis[X];
	pixel.axis[Y] = start.axis[Y];
	while (pixels > 0)
	{
		pixel.color = gradient(start.color, end.color, len, len - pixels);
		my_putpixel(meta, pixel);
		pixel.axis[X] += delta.axis[X];
		pixel.axis[Y] += delta.axis[Y];
		pixels = pixels - 1;
	}
	return (1);
}

void	wire_line(t_point *point, t_meta *meta, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	x_end = 0;
	while (i < (int)meta->map[0].limits.axis[X])
	{
		x_end = i + density;
		if (x_end >= (int)meta->map[0].limits.axis[X])
			x_end = (int)meta->map[0].limits.axis[X] - 1;
		y_end = i + (int)meta->map[0].limits.axis[X] * density;
		if (point[i].paint)
		{
			draw_line(meta, point[i], point[x_end]);
			if (line + density < (int)meta->map[0].limits.axis[Y])
				draw_line(meta, point[i], point[y_end]);
		}
		i++;
	}
}

void	wired(t_meta *meta, t_point *wire, int n_map)
{
	int	i;
	int	density;

	density = 1 / meta->map[n_map].scale;
	if (density == 0)
		density = 1;
	i = 0;
	while (i < meta->map[n_map].len)
	{
		wire_line(&wire[i], meta, density, i / meta->map[n_map].limits.axis[X]);
		i = i + meta->map[n_map].limits.axis[X] * density;
	}
}

int	draw_map(t_meta *meta)
{
	t_point	*proyect;
	int		n_map;

	mlx_destroy_image(meta->vars.mlx, meta->bitmap.img);
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
	&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
	n_map = 0;
	if (meta->map[0].b_stars)
		paint_stars(meta);
	while (meta->n_maps >= n_map && (meta->map[n_map].visible == 1))
	{
		proyect = malloc (meta->map[n_map].len * sizeof(t_point));
		if (proyect == NULL)
			exit(1);
		meta->map[n_map].renders = meta->map[n_map].renders + 1;
		copy_map(meta->map[n_map].points, proyect, meta->map[n_map].len);
		parse_map(meta, proyect, n_map);
		wired(meta, proyect, n_map);
		free (proyect);
		n_map++;
	}
	mlx_put_image_to_window(meta->vars.mlx, meta->vars.win, \
	meta->bitmap.img, 0, 0);
	return (1);
}
