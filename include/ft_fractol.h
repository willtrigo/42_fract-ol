/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:59:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 14:10:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "../lib/42_libft/include/libft.h"
# include <math.h>
# include <errno.h>

# define WIDTH 1920
# define HEIGHT 1080
# define NAME_WINDOW "42sp - dande-je's fract-ol | type of fractal - "

// typedef struct s_assets	t_assets;
// struct s_assets
// {
// 	mlx_texture_t	*t_icon;
// };

typedef struct s_fractal	t_fractal;
struct s_fractal
{
	uint32_t	x;
	uint32_t	y;
	int			xpos;
	int			ypos;
	double		xzoom;
	double		yzoom;
	double		xmax;
	double		xmin;
	double		ymax;
	double		ymin;
	double		creal;
	double		cimag;
	int			max_iter;
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	double		ccolor;
};


typedef struct s_canvas	t_canvas;
struct s_canvas
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	char			*title_window;
	mlx_texture_t	*icon;
	t_fractal		*fractal;
};

void	ft_parse_fractal(int32_t argc, char **map);
void	ft_parse_julia(char **map);
void	ft_parse_mandelbrot(int32_t argc);
void	ft_create_fractal(char **map);
void	ft_key_hook(mlx_key_data_t key, t_canvas *param);
void	ft_load_assets(t_canvas *data);
void	ft_free_fractal_assets(t_canvas *data);
void	ft_free_fractal(t_canvas *data);
void	ft_free_fractal(t_canvas *data);

#endif
