/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 00:49:57 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 00:50:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
# define FT_STRUCTS_H

# include "ft_fractol.h"

typedef struct s_color		t_color;
struct s_color
{
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;
	double	rgb;
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
	mlx_image_t		*bg;
	char			*title_window;
	char			*name;
	mlx_texture_t	*icon;
	t_fractal		*fractal;
};

#endif
