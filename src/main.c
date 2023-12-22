/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 00:27:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int32_t	main(int32_t argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		ft_putstr_fd("\033[0;31mUsage:\033[0m ./fractol [fractal type] [fractal constant]\n", STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_parse_fractal(argc, argv);
	ft_create_fractal(argv);
	exit(EXIT_SUCCESS);
}
