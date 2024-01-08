/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_fractal.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 01:38:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 08:27:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FUNCTIONS_FRACTAL_H
# define FT_FUNCTIONS_FRACTAL_H

# include "ft_fractol.h"

void		ft_help(void);
void		ft_parse_julia(char **map);
void		ft_set_julia(t_complex *c, t_canvas *data);
void		ft_parse_mandelbrot(int32_t argc);
int32_t		ft_bernstein_poly(uint32_t i, int32_t a);
int32_t		ft_color(int32_t r, int32_t g, int32_t b, int32_t a);
void		ft_key_hook(mlx_key_data_t key, t_canvas *param);
void		ft_scroll_hook(double xdelta, double ydelta, t_canvas *data);
void		ft_create_canvas(char **map);
void		ft_free_fractal(t_canvas *data);
void		ft_load_assets(t_canvas *data);
void		ft_get_complex(t_canvas *data, t_complex *z, t_complex *c,
				t_complex *x_y);
double		ft_get_z_complex(double offset, double min, double max,
				double zoom);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
void		ft_parse_fractal(int32_t argc, char **map);
void		ft_render_fractal(t_canvas *data);
void		ft_render_bg(t_canvas *data);

#endif
