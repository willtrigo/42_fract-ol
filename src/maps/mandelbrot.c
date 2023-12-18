/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:05:54 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/18 19:07:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_parse_mandelbrot(int32_t argc)
{
	if (argc > 2)
	{
		ft_putstr_fd("\033[0;31mInvalid Mandelbrot\033[0m - Too many argumments\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}
