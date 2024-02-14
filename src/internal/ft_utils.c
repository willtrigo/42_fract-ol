/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:07:25 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/14 01:37:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_utils.h"

void	ft_help(void)
{
	ft_putstr_fd("\t\t\t", STDOUT_FILENO);
	ft_putstr_fd("\033[0;36m== FRACTOL GUIDE ==\033[0m\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
	ft_putstr_fd("\t\t\t  ", STDOUT_FILENO);
	ft_putstr_fd("\033[0;33mArguments Guide:\033[0m\n\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol julia X.XXXXX X.XXXXX\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
	ft_putstr_fd("\t\t\t    ", STDOUT_FILENO);
	ft_putstr_fd("\033[0;33mJulia tips:\033[0m\n\n", STDOUT_FILENO);
	ft_putstr_fd("(-0.835,   -0.2321)\t(0.285,  0.0)\t\t(0.285,    0.01)\n", \
		STDOUT_FILENO);
	ft_putstr_fd("(-0.5239,  -0.69969)\t(0.45,   0.1428)\t", STDOUT_FILENO);
	ft_putstr_fd("(-0.70469, -0.5239)\n", STDOUT_FILENO);
	ft_putstr_fd("(-0.70176, -0.3842)\t(-0.312, 0.0)\n", STDOUT_FILENO);
	ft_putstr_fd("\n\033[0;32mAny range between 2 and ", STDOUT_FILENO);
	ft_putstr_fd("-2, it's a fractal valid in Julia arguments\033[0m\n", \
		STDOUT_FILENO);
	ft_putstr_fd("----------------------------------", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
}

void	ft_output_error(char *str_title, char *str_message)
{
	ft_help();
	ft_putstr_fd("\033[0;31m", STDERR_FILENO);
	ft_putstr_fd(str_title, STDERR_FILENO);
	ft_putstr_fd("\033[0m - ", STDERR_FILENO);
	ft_putstr_fd(str_message, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
