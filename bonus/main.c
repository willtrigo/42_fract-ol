/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/18 03:23:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "ft_utils_bonus.h"
#include "ft_parse_fractal_bonus.h"
#include "ft_canvas_bonus.h"

int32_t	main(int32_t argc, char **argv)
{
	if (argc < 2 || argc > 4)
		ft_output_error("Invalid Fractal", \
			"./fractol [fractal type] [fractal constant]");
	ft_parse_fractal(argc, argv);
	ft_create_canvas(argv);
	exit(EXIT_SUCCESS);
}
