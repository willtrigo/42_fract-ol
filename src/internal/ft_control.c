/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:56:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/14 17:17:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_control.h"

static void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas *data);

void	ft_key_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
}

void	ft_scroll_hook(double xdelta, double ydelta, t_canvas *data)
{
	(void)xdelta;
	if (ydelta > 0.0 && !data->render)
		ft_zoom_hook(ZOOM_IN, data);
	else if (ydelta < 0.0 && !data->render)
		ft_zoom_hook(ZOOM_OUT, data);
}

static void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas *data)
{
	if (!data->render)
	{
		data->render = RENDER_ON;
		data->chronometer = 0.0;
		if (zoom_in_out == ZOOM_IN && data->fractal->zoom.x > ZOOM_MAX)
		{
			data->fractal->zoom.x -= data->fractal->zoom.x / SPEED * 2;
			data->fractal->zoom.y -= data->fractal->zoom.y / SPEED * 2;
		}
		else if (zoom_in_out == ZOOM_OUT \
			&& data->fractal->zoom.x < data->zoom_init)
		{
			data->fractal->zoom.x += data->fractal->zoom.x / SPEED * 2;
			data->fractal->zoom.y += data->fractal->zoom.y / SPEED * 2;
		}
		if (data->fractal->zoom.x > data->zoom_init)
		{
			data->fractal->zoom.x = data->zoom_init;
			data->fractal->zoom.y = data->zoom_init;
		}
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}
