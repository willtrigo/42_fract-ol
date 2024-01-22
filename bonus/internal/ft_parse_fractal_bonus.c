/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fractal_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:54:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:04:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_parse_fractal_bonus.h"

static void	ft_parse_julia(char **map);

void	ft_parse_fractal(int32_t argc, char **map)
{
	if (!ft_strncmp(map[1], "julia", ft_str_len("julia")))
		ft_parse_julia(map);
	else if (!ft_strncmp(map[1], "mandelbrot", ft_str_len("mandelbrot")))
	{
		if (argc > 2)
			ft_output_error("Invalid Mandelbrot", "Too many argumments.");
	}
	else if (!ft_strncmp(map[1], "tricorn", ft_str_len("tricorn")))
	{
		if (argc > 2)
			ft_output_error("Invalid Tricorn", "Too many argumments.");
	}
	else
		ft_output_error("Invalid Fractal", \
			"./fractol [fractal type] [fractal constant]");
}

static void	ft_parse_julia(char **map)
{
	if (!map[2] || !ft_isdouble(map[2]))
		ft_output_error("Invalid Julia", "Invalid constant real.");
	else if ((ft_atof(map[2]) > MAX) || (ft_atof(map[2]) < MIN))
		ft_output_error("Invalid Julia", "Invalid constant real.");
	else if (!map[3] || !ft_isdouble(map[3]))
		ft_output_error("Invalid Julia", "Invalid constant imaginary.");
	else if ((ft_atof(map[3]) > MAX) || (ft_atof(map[3]) < MIN))
		ft_output_error("Invalid Julia", "Invalid constant imaginary.");
}
