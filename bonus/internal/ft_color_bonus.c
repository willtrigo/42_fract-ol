/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:32:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 04:10:45 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color_bonus.h"

int32_t	ft_bernstein_poly(uint32_t i, int32_t a, t_canvas *data)
{
	double	r;
	double	b;
	double	g;
	int32_t	color;

	r = (1.0 * i / MAX_DEFINITION) + data->r_shitf;
	g = (1.0 * i / MAX_DEFINITION) + data->g_shitf;
	b = (1.0 * i / MAX_DEFINITION) + data->b_shitf;
	color = ft_color(255 * 9 * (1.0 - r) * pow(r, 3.0), \
	255 * 15 * pow((1.0 - g), 2.0) * pow(g, 2.0), \
	255 * 8.5 * pow((1.0 - b), 3.0) * b, a).value;
	return (color);
}

t_color	ft_color(int8_t r, int8_t g, int8_t b, int8_t a)
{
	return ((t_color){.r = r, .g = g, .b = b, .a = a});
}
