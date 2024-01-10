/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:07:25 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:50:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils_bonus.h"

void	ft_help(void)
{
	ft_putstr_fd("== FRACTOL GUIDE ==\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
	ft_putstr_fd("Arguments Guide:\n\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol mandelbrot\n", STDOUT_FILENO);
	ft_putstr_fd("./fractol julia X.XXXXX X.XXXXX\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
	ft_putstr_fd("Julia tips: \n\n", STDOUT_FILENO);
	ft_putstr_fd("(-0.391, -0.587)\t(-0.4, -0.6)\t\t(-0.835, -0.2321)\n", \
		STDOUT_FILENO);
	ft_putstr_fd("(0.285, 0.0)\t\t(0.285, 0.01)\t\t(-0.74, 0.12)\n", \
		STDOUT_FILENO);
	ft_putstr_fd("(-1.312, 0.0)\t\t(0.37, -0.28)\t\t(0.45, 0.1428)\n", \
		STDOUT_FILENO);
	ft_putstr_fd("(-0.70176, -0.3842)\t(-0.70469, -0.5239)\t", STDOUT_FILENO);
	ft_putstr_fd("(-0.5239, 0.69969)\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
}
