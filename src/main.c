/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 17:04:00 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/17 15:53:14 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/../inc/main.h"

static void	mlx_init_meta(t_meta *meta)
{
	meta->vars.mlx = mlx_init();
	meta->vars.win = mlx_new_window(meta->vars.mlx, \
		WINX, WINY, "| FDF | Adrian R. E. Herrera @adherrer");
	meta->bitmap.img = mlx_new_image(meta->vars.mlx, WINX, WINY);
	meta->bitmap.buffer = mlx_get_data_addr(meta->bitmap.img, \
		&meta->bitmap.bitxpixel, &meta->bitmap.lines, &meta->bitmap.endian);
}

static void	mlx_listen_meta(t_meta *meta)
{
	mlx_hook(meta->vars.win, 4, 1L << 2, mouse_press, meta);
	mlx_hook(meta->vars.win, 5, 1L << 3, mouse_release, meta);
	mlx_hook(meta->vars.win, 6, 1L << 6, mouse_move, meta);
	mlx_hook(meta->vars.win, 2, 1, key_press, meta);
	mlx_hook(meta->vars.win, 17, 1, terminate_program, meta);
	mlx_put_image_to_window(meta->vars.mlx, \
	meta->vars.win, meta->bitmap.img, 0, 0);
	mlx_loop(meta->vars.mlx);
}

int	main(int argv, char **argc)
{
	t_meta	meta;

	if (argv <= 1)
		return (0);
	meta.map = ft_calloc (MAP_SIZE + 1, sizeof(t_map));
	load_map(&meta, argc[1]);
	mlx_init_meta(&meta);
	config_c_position(meta.map);
	draw_map(&meta);
	mlx_listen_meta(&meta);
	return (0);
}
