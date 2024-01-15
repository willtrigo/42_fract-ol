/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fractal_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:54:16 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 09:29:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_fractal_bonus.h"

static void	ft_parse_julia(char **map);
static void	ft_output_error(char *str_title, char *str_message);

void	ft_parse_fractal(int32_t argc, char **map)
{
	if (!ft_strncmp(map[1], "julia", ft_str_len("julia")))
		ft_parse_julia(map);
	else if (!ft_strncmp(map[1], "mandelbrot", ft_str_len("mandelbrot")))
	{
		if (argc > 2)
			ft_output_error("Invalid Mandelbrot", "Too many argumments.");
	}
	else
	{
		ft_help();
		exit(EXIT_FAILURE);
	}
}

void	ft_set_julia(t_complex *c, t_canvas *data)
{
	c->x = data->fractal->julia_const.x;
	c->y = data->fractal->julia_const.y;
}

static void	ft_parse_julia(char **map)
{
	if (!map[2] || !ft_isdouble(map[2]))
		ft_output_error("Invalid Julia", "constant real invalid.");
	else if ((ft_atof(map[2]) > 2.0) || (ft_atof(map[2]) < -2.0))
		ft_output_error("Invalid Julia", "constant real invalid.");
	else if (!map[3] || !ft_isdouble(map[3]))
		ft_output_error("Invalid Julia", "constant imaginary invalid.");
	else if ((ft_atof(map[3]) > 2.0) || (ft_atof(map[3]) < -2.0))
		ft_output_error("Invalid Julia", "constant imaginary invalid.");
}

static void	ft_output_error(char *str_title, char *str_message)
{
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	ft_putstr_fd(str_title, STDERR_FILENO);
	ft_putstr_fd("\033[0m - ", STDERR_FILENO);
	ft_putstr_fd(str_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	ft_help();
	exit(EXIT_FAILURE);
}
