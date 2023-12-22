/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:54:16 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/21 00:52:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_parse_fractal(int32_t argc, char **map)
{
	if (!ft_strncmp(map[1], "julia", ft_str_len("julia")))
		ft_parse_julia(map);
	else if (!ft_strncmp(map[1], "mandelbrot", ft_str_len("mandelbrot")))
		ft_parse_mandelbrot(argc);
}
