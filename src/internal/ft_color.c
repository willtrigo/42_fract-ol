/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:32:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 01:19:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

int32_t	ft_bernstein_poly(uint32_t i, int32_t a)
{
	double	r;
	double	b;
	double	g;
	int32_t	color;

	r = 17.0 * i / MAX_DEFINITION;
	g = 2.0 * i / MAX_DEFINITION;
	b = 2.0 * i / MAX_DEFINITION;
	color = ft_color(255 * 9 * (1.0 - r) * pow(r, 3.0), \
	255 * 15 * pow((1.0 - g), 2.0) * pow(g, 2.0), \
	255 * 8.5 * pow((1.0 - b), 3.0) * b, a).value;
	return (color);
}

t_color	ft_color(int8_t r, int8_t g, int8_t b, int8_t a)
{
	return ((t_color){.r = r, .g = g, .b = b, .a = a});
}
