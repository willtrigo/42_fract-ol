/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:07:25 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 08:07:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_help(void)
{
	ft_putstr_fd("== FRACTOL GUIDE ==\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Arguments Guide:\n\n", 1);
	ft_putstr_fd("./fractol mandelbrot\n", 1);
	ft_putstr_fd("./fractol julia X.XXXXX X.XXXXX\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
	ft_putstr_fd("Julia tips: \n\n", 1);
	ft_putstr_fd("(-0.391, -0.587)\t(-0.4, -0.6)\t\t(-0.835, -0.2321)\n", 1);
	ft_putstr_fd("(0.285, 0.0)\t\t(0.285, 0.01)\t\t(-0.74, 0.12)\n", 1);
	ft_putstr_fd("(-1.312, 0.0)\t\t(0.37, -0.28)\t\t(0.45, 0.1428)\n", 1);
	ft_putstr_fd("(-0.70176, -0.3842)\t(-0.70469, -0.5239)\t", 1);
	ft_putstr_fd("(-0.5239, 0.69969)\n", 1);
	ft_putstr_fd("----------------------------------\n", 1);
}
