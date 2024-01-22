/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:12:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 08:51:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_canvas.h"

static void	ft_init_fractal(t_canvas *data, char *name, char **value);

void	ft_create_canvas(char **map)
{
	t_canvas	data;

	data.name = ft_strdup(map[1]);
	data.title_window = ft_strjoin(NAME_WINDOW, data.name);
	data.mlx = mlx_init(WIDTH, HEIGHT, data.title_window, false);
	data.canvas = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.fractal = ft_calloc(1, sizeof(t_fractal));
	ft_init_fractal(&data, data.name, map);
	data.render = RENDER_ON;
	ft_render_fractal(&data);
	mlx_image_to_window(data.mlx, data.canvas, 0, 0);
	ft_load_assets(&data);
	mlx_set_icon(data.mlx, data.icon);
	mlx_key_hook(data.mlx, (mlx_keyfunc)ft_key_hook, &data);
	mlx_scroll_hook(data.mlx, (mlx_scrollfunc)ft_scroll_hook, &data);
	mlx_loop(data.mlx);
	ft_clean(&data);
	mlx_terminate(data.mlx);
}

void	ft_reset_fractal(t_canvas *data)
{
	data->zoom_init = ZOOM_INIT;
	data->fractal->zoom.x = data->zoom_init;
	data->fractal->zoom.y = data->zoom_init;
	data->fractal->offset.x = 0.0;
	data->fractal->offset.y = 0.0;
	data->r_shitf = 10.9;
	data->b_shitf = 0.0;
	data->g_shitf = 0.0;
}

static void	ft_init_fractal(t_canvas *data, char *name, char **value)
{
	ft_reset_fractal(data);
	if (!ft_strncmp(name, "julia", ft_str_len("julia")))
	{
		data->fractal->c.x = ft_atof(value[2]);
		data->fractal->c.y = ft_atof(value[3]);
	}
}
