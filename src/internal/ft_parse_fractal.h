/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fractal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:39:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/09 06:38:33 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_FRACTAL_H
# define FT_PARSE_FRACTAL_H

# include <errno.h>
# include "MLX42/MLX42.h"
# include "ft_non-standard.h"
# include "ft_string.h"
# include "ft_canvas.h"
# include "ft_utils.h"

void	ft_parse_fractal(int32_t argc, char **map);
void	ft_parse_julia(char **map);
void	ft_set_julia(t_complex *c, t_canvas *data);
void	ft_parse_mandelbrot(int32_t argc);

#endif
