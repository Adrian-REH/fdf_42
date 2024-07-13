/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:15:35 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:21:02 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../inc/../inc/positions.h"

void	config_g_position(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len)
	{
		map[i].b_geo = 1;
		map[i].scale = 3;
		map[i].visible = 1;
		map[i].scale = (3 - (i * (0.5)));
		map[i].min_scale = 3 - i * 0.5;
		if (i)
		{
			map[i].source.axis[X] = map[0].source.axis[X] + \
			(map[1].limits.axis[X] / 3) * ((rand() % 21) - 10);
			map[i].source.axis[Y] = map[0].source.axis[Y] + \
			(map[1].limits.axis[Y] / 3) * ((rand() % 21) - 10);
		}
		i++;
	}
}

void	config_c_position(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len)
	{
		map[i].b_geo = 0;
		map[i].b_cil = 0;
		map[i].scale = 1;
		map[i].min_scale = 1;
		if (i)
			map[i].visible = 0;
		i++;
	}
}

void	config_tr_position(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len)
	{
		map[i].b_geo = ((map[i].b_cil = 1), (map[i].visible = 1), (0));
		map[i].scale = (0.15 * (i * i) - (0.65 * i) + 1);
		map[i].source.axis[X] = map[0].source.axis[X] + \
		(map[0].limits.axis[X]) * ((1.958333333 * (i * i)) - (3.083333333 * i));
		if (i)
			map[i].source.axis[Y] = map[0].source.axis[Y] - \
			map[0].limits.axis[X] / 2;
		if (i > 2 && i <= 5)
		{
			map[i].b_geo = ((map[i].b_cil = 0), (map[i].scale = -2 + i), (1));
			map[i].source.axis[Y] = map[0].source.axis[Y] - \
			map[0].limits.axis[Y] / 3.5;
			map[i].source.axis[X] = map[0].source.axis[X] + \
			(map[0].limits.axis[X]) * (-0.25 * (i - 3) + 0.5);
		}
		map[i].min_scale = map[i].scale;
		i++;
	}
	map[4].source.axis[X] = map[0].source.axis[X] - \
	(map[0].limits.axis[X]) / 3.5;
}
