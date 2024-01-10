/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/09 06:12:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "ft_utils.h"
#include "ft_parse_fractal.h"
#include "ft_canvas.h"

int32_t	main(int32_t argc, char **argv)
{
	if (argc < 2 || argc > 4)
	{
		ft_putstr_fd("\033[0;31mUsage:", STDERR_FILENO);
		ft_putstr_fd("\033[0m ./fractol [fractal type] [fractal constant]\n", \
			STDERR_FILENO);
		ft_help();
		exit(EXIT_FAILURE);
	}
	ft_parse_fractal(argc, argv);
	ft_create_canvas(argv);
	exit(EXIT_SUCCESS);
}
