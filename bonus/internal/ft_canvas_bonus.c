/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:52:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas_bonus.h"

static void	ft_init_fractal(t_fractal *fractal, char *name, char **data);

void	ft_create_canvas(char **map)
{
	t_canvas	data;

	data.name = ft_strdup(map[1]);
	data.title_window = ft_strjoin(NAME_WINDOW, data.name);
	data.mlx = mlx_init(WIDTH, HEIGHT, data.title_window, true);
	data.bg = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.canvas = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.fractal = ft_calloc(1, sizeof(t_fractal));
	data.r_shitf = 17.0;
	ft_init_fractal(data.fractal, data.name, map);
	ft_render_bg(&data);
	ft_render_fractal(&data);
	mlx_image_to_window(data.mlx, data.canvas, 0, 0);
	mlx_image_to_window(data.mlx, data.bg, 0, 0);
	ft_load_assets(&data);
	mlx_set_icon(data.mlx, data.icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc)ft_scroll_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_clean(&data);
}

static void	ft_init_fractal(t_fractal *fractal, char *name, char **data)
{
	fractal->zoom.x = ZOOM_INIT;
	fractal->zoom.y = ZOOM_INIT;
	if (!ft_strncmp(name, "julia", ft_str_len("julia")))
	{
		fractal->julia_const.x = ft_atof(data[2]);
		fractal->julia_const.y = ft_atof(data[3]);
	}
}
