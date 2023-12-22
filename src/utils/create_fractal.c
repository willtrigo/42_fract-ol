/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:51 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 01:57:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_create_fractal(char **map)
{
	t_fractal	data;

	data.assets = ft_calloc(1, sizeof(t_assets));
	data.title_window = ft_strjoin(NAME_WINDOW, map[1]);
	data.mlx = mlx_init(WIDTH, HEIGHT, data.title_window, true);
	data.canvas = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	mlx_image_to_window(data.mlx, data.canvas, 0, 0);
	ft_load_assets(&data);
	mlx_set_icon(data.mlx, data.assets->t_icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_fractal(&data);
}
