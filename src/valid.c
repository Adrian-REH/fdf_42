/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 00:11:15 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 21:05:31 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/../inc/valid.h"

int	valid_point(char *value)
{
	int	valid;

	valid = 0;
	if (*value == '-' || *value == '+' || ft_isdigit(*value))
		valid++;
	value++;
	while (ft_isdigit(*value))
	{
		value++;
		valid++;
	}
	if (valid == 0)
		return (0);
	else
		return (1);
}

int	valid_extension(char *path)
{
	int	i;

	i = 0;
	if (ft_strlen(path) <= 4)
		exit(1);
	while (path[i])
	{
		if (path[i] == '.' && path[i + 1] == 'f' && \
		path[i + 2] == 'd' && path[i + 3] == 'f')
			return (1);
		i++;
	}
	exit(1);
}
