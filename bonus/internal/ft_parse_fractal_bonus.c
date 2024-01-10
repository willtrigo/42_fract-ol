/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fractal_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:54:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:49:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_fractal_bonus.h"

void	ft_parse_fractal(int32_t argc, char **map)
{
	if (!ft_strncmp(map[1], "julia", ft_str_len("julia")))
		ft_parse_julia(map);
	else if (!ft_strncmp(map[1], "mandelbrot", ft_str_len("mandelbrot")))
		ft_parse_mandelbrot(argc);
	else
	{
		ft_help();
		exit(EXIT_FAILURE);
	}
}

void	ft_parse_julia(char **map)
{
	if (!ft_isdouble(map[2]))
	{
		ft_putstr_fd("\033[0;31mInvalid Julia", STDERR_FILENO);
		ft_putstr_fd("\033[0m - constant real invalid.\n", STDERR_FILENO);
		ft_help();
		exit(EXIT_FAILURE);
	}
	if (!map[3] || !ft_isdouble(map[3]))
	{
		ft_putstr_fd("\033[0;31mInvalid Julia", STDERR_FILENO);
		ft_putstr_fd("\033[0m - constant imaginary invalid.\n", STDERR_FILENO);
		ft_help();
		exit(EXIT_FAILURE);
	}
}

void	ft_set_julia(t_complex *c, t_canvas *data)
{
	c->x = data->fractal->julia_const.x;
	c->y = data->fractal->julia_const.y;
}

void	ft_parse_mandelbrot(int32_t argc)
{
	if (argc > 2)
	{
		ft_putstr_fd("\033[0;31mInvalid Mandelbrot", STDERR_FILENO);
		ft_putstr_fd("\033[0m - Too many argumments\n", STDERR_FILENO);
		ft_help();
		exit(EXIT_FAILURE);
	}
}
