/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:51:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 19:51:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_BONUS_H
# define FT_MATH_BONUS_H

# include "ft_string.h"
# include "ft_fractol_bonus.h"

void		ft_get_complex(t_canvas *data, t_complex *z, t_complex *c, \
				t_complex *x_y);
double		ft_get_z_complex(double offset, double min, double max, \
				double zoom);
t_complex	ft_sum_complex(t_complex z, t_complex c);
t_complex	ft_square_z_complex(t_complex z, double value);

#endif
