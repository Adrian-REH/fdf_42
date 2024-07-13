/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peripheral.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:02:13 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/peripheral.h"

int	terminate_program(void *param)
{
	t_meta	*meta;

	meta = (t_meta *)param;
	free(meta->map[0].points);
	free(meta->map);
	exit(0);
}

/* 
*	This function handle when a key is pressed
*/
int	key_press(int key, void *param)
{
	t_meta	*meta;

	meta = (t_meta *) param;
	if (key == XK_c)
	{
		meta->b_soft = 0;
		config_c_position(meta->map);
	}
	if (key == XK_t)
	{
		meta->b_soft = 1;
		(config_c_position(meta->map), config_tr_position(meta->map));
	}
	if (key == XK_g)
	{
		meta->b_soft = 1;
		(config_c_position(meta->map), config_g_position(meta->map));
		meta->map[0].b_stars = !meta->map[0].b_stars;
	}
	if (key == XK_i)
		isometric(meta->map);
	if (key == XK_Escape)
		terminate_program(param);
	draw_map(meta);
	return (0);
}

/* 
*	This function handle every time a mouse button is relased
*/

int	mouse_release(int button, int x, int y, void *param)
{
	t_meta	*meta;

	(void)x;
	(void)y;
	meta = (t_meta *)param;
	if (button == 1)
		meta->keys.b_mouse_l = 0;
	if (button == 2)
		meta->keys.b_mouse_r = 0;
	return (0);
}

/* 
*	This function handle every time the mouse is moved
*/
int	mouse_move(int x, int y, void *param)
{
	t_meta	*meta;

	(meta = (t_meta *)param);
	if (x > WINX || x < 0 || y > WINY || y < 0)
		return (0);
	update_map_angles_and_positions(x, y, meta);
	if (meta->keys.b_mouse_l)
	{
		meta->keys.last_click_l.axis[X] = x;
		meta->keys.last_click_l.axis[Y] = y;
		draw_map(meta);
	}
	if (meta->keys.b_mouse_r)
	{
		meta->keys.last_click_r.axis[X] = x;
		meta->keys.last_click_r.axis[Y] = y;
		draw_map(meta);
	}
	return (0);
}

/* 
*	This function handle every time a mouse button is pressed
*/
int	mouse_press(int button, int x, int y, void *param)
{
	t_meta	*meta;
	int		n_map;

	n_map = ((meta = (t_meta *)param), (meta->n_maps));
	if (button == 1)
	{
		meta->keys.b_mouse_l = ((meta->keys.last_click_l.axis[X] = x), 1);
		meta->keys.last_click_l.axis[Y] = y;
	}
	if (button == 2)
	{
		meta->keys.b_mouse_r = ((meta->keys.last_click_r.axis[X] = x), 1);
		meta->keys.last_click_r.axis[Y] = y;
	}
	while (n_map-- > 0)
	{
		if (button == 5)
		{
			if ((meta->map[n_map].scale) > meta->map[n_map].min_scale)
				meta->map[n_map].scale = meta->map[n_map].scale / 1.5;
		}
		if (button == 4)
			meta->map[n_map].scale = meta->map[n_map].scale * 1.5;
	}
	return (draw_map(meta), 0);
}
