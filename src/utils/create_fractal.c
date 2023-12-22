/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:51 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 16:45:48 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_init_fractal(t_fractal *fractal, char *name, char **data);

void	ft_create_fractal(char **map)
{
	t_canvas	data;

	data.title_window = ft_strjoin(NAME_WINDOW, map[1]);
	data.mlx = mlx_init(WIDTH, HEIGHT, data.title_window, true);
	data.canvas = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.fractal = ft_calloc(1, sizeof(t_fractal));
	ft_init_fractal(data.fractal, map[1], map);
	mlx_image_to_window(data.mlx, data.canvas, 0, 0);
	ft_load_assets(&data);
	mlx_set_icon(data.mlx, data.icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free_fractal(&data);
}

void	ft_init_fractal(t_fractal *fractal, char *name, char **data)
{
	fractal->max_iter = 100;
	fractal->xmax = 2.0;
	fractal->xmin = -2.0;
	fractal->ymax = 2.0;
	fractal->ymin = -2.0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->ccolor = 1;
	if (!ft_strncmp(name, "julia", ft_str_len("julia")))
	{
		fractal->creal = ft_atof(data[2]);
		fractal->cimag = ft_atof(data[3]);
	}
}
