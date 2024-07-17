/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adherrer <adherrer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 16:57:10 by adherrer          #+#    #+#             */
/*   Updated: 2024/07/17 11:00:54 by adherrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H
# include <time.h>
# include <strings.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
# include <stdbool.h>
# define MENU_WIDTH			0
# define WINX 1280	
# define WINY 720
# define X 0
# define Y 1
# define Z 2
# define ROJO 		0xc1272d
# define VERDE		0x33cc55
# define FUCSIA 	0xff255c
# define AZUL		0x1B8EFA
# define SUPERAZUL	0x0000FF
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D
# define BLOCK_READ 500000
# define DEFAULT_COLOR		JAFFA
# define BOTTOM_COLOR		AZUL
# define TOP_COLOR			BRICK_RED
# define GROUND_COLOR		SAFFRON
# define BACK_COLOR			0x151515

# define FREE				0

typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	bool	paint;
	float	polar[2][2];
}			t_point;

typedef struct m_colors
{
	int	topcolor;
	int	groundcolor;
	int	bottomcolor;
}		t_colors;

typedef struct s_bitmap
{
	void	*img;
	char	*buffer;
	int		bitxpixel;
	int		lines;
	int		endian;
}			t_bitmap;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_keys
{
	bool	b_mouse_l;
	bool	b_mouse_r;
	bool	b_keyctrl;
	t_point	last_click_l;
	t_point	last_click_r;
}			t_keys;

typedef struct m_map
{
	t_point		*points;
	t_point		limits;
	t_point		source;
	t_colors	colors;
	char		*memory;
	char		**lines;
	int			zmin;
	float		ang_base[3];
	float		ang[3];
	float		scale;
	float		visible;
	float		min_scale;
	int			len;
	int			renders;
	bool		b_geo;
	bool		b_cil;
	bool		b_stars;
	bool		b_shadow;
	double		performance;
	float		proportion;
	float		radius;
}				t_map;

typedef struct s_meta
{
	t_vars		vars;
	t_bitmap	bitmap;
	t_map		*map;
	t_keys		keys;
	int			n_maps;
	int			b_soft;
}				t_meta;

#endif