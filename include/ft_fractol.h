/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:59:55 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 03:34:22 by dande-je         ###   ########.fr       */
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
# define NAME_WINDOW "42sp - dande-je's fract-ol project | type of fractal - "

typedef struct s_assets		t_assets;
struct s_assets
{
	mlx_texture_t	*t_icon;
};

typedef struct s_fractal	t_fractal;
struct s_fractal
{
	mlx_t			*mlx;
	mlx_image_t		*canvas;
	char			*title_window;
	t_assets		*assets;
};

void	ft_parse_fractal(int32_t argc, char **map);
void	ft_parse_julia(char **map);
void	ft_parse_mandelbrot(int32_t argc);
void	ft_create_fractal(char **map);
void	ft_key_hook(mlx_key_data_t key, t_fractal *param);
void	ft_load_assets(t_fractal *data);
void	ft_free_fractal_assets(t_fractal *data);
void	ft_free_fractal(t_fractal *data);
void	ft_free_fractal(t_fractal *data);

#endif
