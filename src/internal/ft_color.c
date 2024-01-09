/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:32:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/09 08:00:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_color.h"

int32_t	ft_bernstein_poly(uint32_t i, int32_t a)
{
	double	num;
	int32_t	color;

	num = 7.0 * i / MAX_DEFINITION;
	color = ft_color(255 * 9 * (1.0 - num) * pow(num, 3.0), \
	255 * 15 * pow((1.0 - num), 2.0) * pow(num, 2.0), \
	255 * 8.5 * pow((1.0 - num), 3.0) * num, a).value;
	return (color);
}

t_color	ft_color(int8_t r, int8_t g, int8_t b, int8_t a)
{
	return ((t_color){.r = r, .g = g, .b = b, .a = a});
}
