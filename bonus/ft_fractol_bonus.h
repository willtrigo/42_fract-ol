/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:59:55 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 08:59:39 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_BONUS_H
# define FT_FRACTOL_BONUS_H

# include "MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 1080
# define MAX 2.0
# define MIN -2.0
# define MAX_DEFINITION 100
# define MAX_VALUE_POLY 4
# define SPEED 9
# define ZOOM_INIT 0.711
# define CONST_COLOR 0.01
# define NAME_WINDOW "42sp - dande-je's fract-ol | type of fractal - "

typedef union u_color		t_color;
union u_color
{
	uint32_t	value;
	struct
	{
		uint8_t	a;
		uint8_t	b;
		uint8_t	g;
		uint8_t	r;
	};
};

typedef struct s_complex	t_complex;
struct s_complex
{
	double	x;
	double	y;
};

typedef struct s_fractal	t_fractal;
struct s_fractal
{
	t_complex	zoom;
	t_complex	offset;
	t_complex	julia_const;
	int32_t		mouse_x;
	int32_t		mouse_y;
	t_color		color;
};

typedef struct s_canvas		t_canvas;
struct s_canvas
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	mlx_texture_t	*icon;
	t_fractal		*fractal;
	double			b_shitf;
	double			g_shitf;
	double			r_shitf;
	char			*title_window;
	char			*name;
};

#endif
