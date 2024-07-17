/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 08:56:05 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/17 13:30:45 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/../inc/projection.h"

/*
*	Set the values to draw ISOMETRIC view
*/
void	isometric(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len)
	{
		map[i].ang[X] = 30;
		map[i].ang[Y] = 330;
		map[i].ang[Z] = 30;
		i++;
	}
}

/*
*	Set the values to draw PARALLEL view
*/
void	parallel(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].len / 2)
	{
		map[i].ang[X] = 90;
		map[i].ang[Y] = 0;
		map[i].ang[Z] = 0;
		i++;
	}
}
