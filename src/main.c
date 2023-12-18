/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/18 20:21:10 by dande-je         ###   ########.fr       */
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
	ft_init_fractol(argc, argv);
	ft_create_fractol(argv);
	return (EXIT_SUCCESS);
}
