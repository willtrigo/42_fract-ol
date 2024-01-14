/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 08:07:25 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/14 11:18:07 by dande-je         ###   ########.fr       */
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
	ft_putstr_fd("(-0.5239, -0.69969)\t(0.285, 0.0)\t(0.285, 0.01)\n", \
		STDOUT_FILENO);
	ft_putstr_fd("(-0.835, -0.2321)\t(0.45, 0.1428)\t", STDOUT_FILENO);
	ft_putstr_fd("(-0.70469, -0.5239)\n", STDOUT_FILENO);
	ft_putstr_fd("(-0.70176, -0.3842)\t(-0.312, 0.0)\n", STDOUT_FILENO);
	ft_putstr_fd("----------------------------------\n", STDOUT_FILENO);
}

void	ft_sleep(t_canvas *data)
{
	volatile int	i;
	volatile int	j;
	volatile int	millisecond_time;

	i = 0;
	j = 0;
	millisecond_time = 10000 * 2000;
	while (i < millisecond_time)
	{
		while (j < 1000)
			j++;
		i++;
	}
	data->render = RENDER_OFF;
}
