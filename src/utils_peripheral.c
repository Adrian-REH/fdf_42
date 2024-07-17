/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_peripheral.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:25:25 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 13:14:18 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/../inc/utils_peripheral.h"

void	update_map_angles_and_positions(int x, int y, t_meta *meta)
{
	int	n_map;

	n_map = meta->n_maps;
	while (n_map-- > 0)
	{
		if (meta->keys.b_mouse_l)
		{
			angle(&meta->map[n_map].ang[X], \
			(int)meta->keys.last_click_l.axis[Y] - y);
			angle(&meta->map[n_map].ang[Y], \
			(int)meta->keys.last_click_l.axis[X] - x);
		}
		if (meta->keys.b_mouse_r)
		{
			meta->map[n_map].source.axis[X] -= \
			((int)meta->keys.last_click_r.axis[X] - x);
			meta->map[n_map].source.axis[Y] -= \
			((int)meta->keys.last_click_r.axis[Y] - y);
			meta->map[n_map].source.axis[Z] = 0;
		}
	}
}
