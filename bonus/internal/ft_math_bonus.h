/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:51:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:51:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_BONUS_H
# define FT_MATH_BONUS_H

# include "ft_string.h"
# include "ft_fractol_bonus.h"

void			ft_get_complex(t_canvas_bonus *data, t_complex_bonus *z, \
					t_complex_bonus *c, t_complex_bonus *x_y);
double			ft_get_z_complex(double offset, double min, double max, \
					double zoom);
t_complex_bonus	ft_sum_complex(t_complex_bonus z, t_complex_bonus c);
t_complex_bonus	ft_square_z_complex(t_complex_bonus z, double value);

#endif
