/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:59:55 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/15 18:42:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_BONUS_H
# define FT_FRACTOL_BONUS_H

# include "MLX42/MLX42.h"

# define WIDTH 1920
# define HEIGHT 995
# define NAME_WINDOW "42sp - dande-je's fract-ol | type of fractal - "
# define MAX 2.0
# define MIN -2.0
# define MAX_DEFINITION 120
# define MAX_COLOR_DEFINITION 250
# define MAX_VALUE_POLY 4
# define SPEED 10
# define ZOOM_INIT 0.618
# define ZOOM_TRICORN_INIT 0.911
# define ZOOM_IN 0x01
# define ZOOM_OUT 0x00
# define ZOOM_MAX 0.000000000000005642
# define CONST_COLOR 0.03
# define CONST_ZOOM 0.01
# define CONST_OFFSET 20
# define DELAY 0.03
# define RENDER_ON 0X01
# define RENDER_OFF 0X00

typedef union u_color_bonus		t_color_bonus;
union u_color_bonus
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

typedef struct s_complex_bonus	t_complex_bonus;
struct s_complex_bonus
{
	double	x;
	double	y;
};

typedef struct s_fractal_bonus	t_fractal_bonus;
struct s_fractal_bonus
{
	t_complex_bonus	zoom;
	t_complex_bonus	offset;
	t_complex_bonus	c;
	int32_t			mouse_x;
	int32_t			mouse_y;
	t_color_bonus	color;
};

typedef struct s_canvas_bonus	t_canvas_bonus;
struct s_canvas_bonus
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	mlx_texture_t	*icon;
	t_fractal_bonus	*fractal;
	double			b_shitf;
	double			g_shitf;
	double			r_shitf;
	double			zoom_init;
	double			delay;
	int32_t			mouse_x;
	int32_t			mouse_y;
	char			*title_window;
	char			*name;
	int8_t			render;
};

#endif
