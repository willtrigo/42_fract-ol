/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:54:16 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/18 19:12:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

static void	ft_parse_fractol(int32_t argc, char **map);

void	ft_init_fractol(int32_t argc, char **map)
{
	ft_parse_fractol(argc, map);
}

static void	ft_parse_fractol(int32_t argc, char **map)
{
	if (!ft_strncmp(map[1], "julia", ft_str_len("julia")))
		ft_parse_julia(map);
	else if (!ft_strncmp(map[1], "mandelbrot", ft_str_len("mandelbrot")))
		ft_parse_mandelbrot(argc);
}
