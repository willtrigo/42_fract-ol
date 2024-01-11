/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 09:00:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_canvas_bonus.h"

static void	ft_init_fractal(t_canvas *data, char *name, char **value);

void	ft_create_canvas(char **map)
{
	t_canvas	data;

	data.name = ft_strdup(map[1]);
	data.title_window = ft_strjoin(NAME_WINDOW, data.name);
	data.mlx = mlx_init(WIDTH, HEIGHT, data.title_window, true);
	data.canvas = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.fractal = ft_calloc(1, sizeof(t_fractal));
	ft_init_fractal(&data, data.name, map);
	ft_render_fractal(&data);
	mlx_image_to_window(data.mlx, data.canvas, 0, 0);
	ft_load_assets(&data);
	mlx_set_icon(data.mlx, data.icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc)ft_scroll_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_clean(&data);
}

void	ft_reset_fractal(t_canvas *data)
{
	data->fractal->zoom.x = ZOOM_INIT;
	data->fractal->zoom.y = ZOOM_INIT;
	data->fractal->offset.x = 0.0;
	data->fractal->offset.y = 0.0;
	data->r_shitf = 3.0;
	data->b_shitf = 0.0;
	data->g_shitf = 0.0;
}

static void	ft_init_fractal(t_canvas *data, char *name, char **value)
{
	ft_reset_fractal(data);
	if (!ft_strncmp(name, "julia", ft_str_len("julia")))
	{
		data->fractal->julia_const.x = ft_atof(value[2]);
		data->fractal->julia_const.y = ft_atof(value[3]);
	}
}
