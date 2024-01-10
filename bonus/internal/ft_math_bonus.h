/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:51:44 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:47:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_BONUS_H
# define FT_MATH_BONUS_H

# include <math.h>
# include "ft_canvas_bonus.h"

void		ft_get_complex(t_canvas *data, t_complex *z, t_complex *c, \
				t_complex *x_y);
double		ft_get_z_complex(double offset, double min, double max, \
				double zoom);
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);

#endif
