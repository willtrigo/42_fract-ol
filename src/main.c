/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 07:55:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/23 04:12:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "MLX42/MLX42.h"
#include "internal/ft_utils.h"
#include "internal/ft_parse.h"
#include "internal/ft_canvas.h"

int32_t	main(int32_t argc, char **argv)
{
	ft_parse_fractal(argc, argv);
	ft_create_canvas(argv);
	exit(EXIT_SUCCESS);
}
