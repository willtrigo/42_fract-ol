/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color_fractal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 20:32:26 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 01:49:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

int32_t	ft_bernstein_poly(uint32_t i, int32_t a)
{
	double	num;
	int32_t	color;

	num = 39.51 * i / MAX_DEFINITION;
	color = ft_color(255 * 9 * (1.0 - num) * pow(num, 3.0), \
	255 * 15 * pow((1.0 - num), 2.0) * pow(num, 2.0), \
	255 * 8.5 * pow((1.0 - num), 3.0) * num, a);
	return (color);
}

int32_t	ft_color(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
