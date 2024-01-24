/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_moviment_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:47:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/24 12:52:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/control/ft_control_moviment_bonus.h"

static void	ft_offset(mlx_key_data_t key, t_canvas_bonus *data);
static void	ft_zoom_in_out(mlx_key_data_t key, t_canvas_bonus *data);

void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas_bonus *data)
{
	if (!data->render)
	{
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
		if (data->fractal->zoom.x > data->zoom_init)
		{
			data->fractal->zoom.x = data->zoom_init;
			data->fractal->zoom.y = data->zoom_init;
		}
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}

void	ft_moviment_hook(mlx_key_data_t key, t_canvas_bonus *data)
{
	ft_offset(key, data);
	ft_zoom_in_out(key, data);
}

void	ft_zoom_offset(int8_t zoom_in_out, t_canvas_bonus *data)
{
	mlx_get_mouse_pos(data->mlx, &data->mouse_x, &data->mouse_y);
	if (zoom_in_out == ZOOM_IN)
	{
		data->fractal->offset.x += (CONST_ZOOM * data->fractal->zoom.x) \
			* ((data->mouse_x - WIDTH / 2) / SPEED);
		data->fractal->offset.y -= (CONST_ZOOM * data->fractal->zoom.y) \
			* ((data->mouse_y - HEIGHT / 2) / SPEED);
	}
	else if (zoom_in_out == ZOOM_OUT)
	{
		data->fractal->offset.x -= (CONST_ZOOM * data->fractal->zoom.x) \
			* ((data->mouse_x - WIDTH / 2) / SPEED);
		data->fractal->offset.y += (CONST_ZOOM * data->fractal->zoom.y) \
			* ((data->mouse_y - HEIGHT / 2) / SPEED);
	}
}

static void	ft_offset(mlx_key_data_t key, t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_RIGHT && !data->render && key.action == MLX_RELEASE)
	{
		data->fractal->offset.x += data->fractal->zoom.x / 30.0;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_LEFT && !data->render && key.action == MLX_RELEASE)
	{
		data->fractal->offset.x -= data->fractal->zoom.x / 30.0;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_UP && !data->render && key.action == MLX_RELEASE)
	{
		data->fractal->offset.y += data->fractal->zoom.x / 30.0;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_DOWN && !data->render && key.action == MLX_RELEASE)
	{
		data->fractal->offset.y -= data->fractal->zoom.x / 30.0;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}

static void	ft_zoom_in_out(mlx_key_data_t key, t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_EQUAL && !data->render)
		ft_zoom_hook(ZOOM_IN, data);
	if (key.key == MLX_KEY_MINUS && !data->render)
		ft_zoom_hook(ZOOM_OUT, data);
}
