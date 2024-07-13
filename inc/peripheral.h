/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   peripheral.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 12:04:21 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/13 10:18:48 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PERIPHERAL_H
# define PERIPHERAL_H
# include "../inc/main.h"

int	key_press(int key, void *param);
int	mouse_release(int button, int x, int y, void *param);
int	mouse_move(int x, int y, void *param);
int	mouse_press(int button, int x, int y, void *param);
int	terminate_program(void *param);

#endif