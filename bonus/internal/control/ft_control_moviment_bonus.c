/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_moviment_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:47:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/13 12:04:46 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control_moviment_bonus.h"

static void	ft_offset(mlx_key_data_t key, t_canvas *data);
static void	ft_zoom_in_out(mlx_key_data_t key, t_canvas *data);

void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas *data)
{
	if (!data->render)
	{
		data->render = RENDER_ON;
		if (zoom_in_out == ZOOM_IN && data->fractal->zoom.x > ZOOM_MAX)
		{
			data->fractal->zoom.x -= data->fractal->zoom.x / SPEED * 2;
			data->fractal->zoom.y -= data->fractal->zoom.y / SPEED * 2;
		}
		else if (zoom_in_out == ZOOM_OUT)
		{
			data->fractal->zoom.x += data->fractal->zoom.x / SPEED * 4;
			data->fractal->zoom.y += data->fractal->zoom.y / SPEED * 4;
		}
		if (data->fractal->zoom.x > ZOOM_INIT)
		{
			data->fractal->zoom.x = ZOOM_INIT;
			data->fractal->zoom.y = ZOOM_INIT;
		}
		ft_render_fractal(data);
	}
}

void	ft_moviment_hook(mlx_key_data_t key, t_canvas *data)
{
	ft_offset(key, data);
	ft_zoom_in_out(key, data);
}

static void	ft_offset(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_RIGHT && !data->render && key.action == MLX_RELEASE)
	{
		data->render = RENDER_ON;
		data->fractal->offset.x += data->fractal->zoom.x / 30.0;
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_LEFT && !data->render && key.action == MLX_RELEASE)
	{
		data->render = RENDER_ON;
		data->fractal->offset.x -= data->fractal->zoom.x / 30.0;
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_UP && !data->render && key.action == MLX_RELEASE)
	{
		data->render = RENDER_ON;
		data->fractal->offset.y += data->fractal->zoom.x / 30.0;
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_DOWN && !data->render && key.action == MLX_RELEASE)
	{
		data->render = RENDER_ON;
		data->fractal->offset.y -= data->fractal->zoom.x / 30.0;
		ft_render_fractal(data);
	}
}

static void	ft_zoom_in_out(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_EQUAL && !data->render)
		ft_zoom_hook(ZOOM_IN, data);
	if (key.key == MLX_KEY_MINUS && !data->render)
		ft_zoom_hook(ZOOM_OUT, data);
}
