/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:23:33 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:04:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COLOR_BONUS_H
# define FT_COLOR_BONUS_H

# include "ft_fractol_bonus.h"
# include "internal/ft_utils_bonus.h"

int32_t			ft_bernstein_poly(uint32_t i, int32_t a, t_canvas_bonus *data);
t_color_bonus	ft_color(int8_t r, int8_t g, int8_t b, int8_t a);

#endif
