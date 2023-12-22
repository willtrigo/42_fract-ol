/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:05:57 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 01:37:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_parse_julia(char **map)
{
	if (!ft_isdouble(map[2]))
	{
		ft_putstr_fd("\033[0;31mInvalid Julia\033[0m - constant real invalid.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ft_isdouble(map[3]))
	{
		ft_putstr_fd("\033[0;31mInvalid Julia\033[0m - constant imaginary invalid.\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
}
