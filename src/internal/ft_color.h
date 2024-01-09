/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:23:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/09 06:38:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_H
# define FT_COLOR_H

# include <math.h>
# include "MLX42/MLX42.h"
# include "ft_fractol.h"
# include "ft_parse_fractal.h"

int32_t	ft_bernstein_poly(uint32_t i, int32_t a);
t_color	ft_color(int8_t r, int8_t g, int8_t b, int8_t a);

#endif
