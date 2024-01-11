/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:56:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 15:01:52 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control_bonus.h"

static void	ft_color_hook(mlx_key_data_t key, t_canvas *data);
static void	ft_moviment_hook(mlx_key_data_t key, t_canvas *data);
static void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas *data);

void	ft_key_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
	ft_moviment_hook(key, data);
	ft_color_hook(key, data);
	ft_render_fractal(data);
}

void	ft_scroll_hook(double xdelta, double ydelta, t_canvas *data)
{
	(void)xdelta;
	if (ydelta > 0.0)
		ft_zoom_hook(ZOOM_IN, data);
	else if (ydelta < 0.0)
		ft_zoom_hook(ZOOM_OUT, data);
	
	ft_render_fractal(data);
}

static void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas *data)
{
	if (zoom_in_out == ZOOM_IN)
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
		data->fractal->offset.x = 0.0;
		data->fractal->offset.y = 0.0;
	}
}

static void	ft_moviment_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_RIGHT)
		data->fractal->offset.x += data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_LEFT)
		data->fractal->offset.x -= data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_UP)
		data->fractal->offset.y += data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_DOWN)
		data->fractal->offset.y -= data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_EQUAL)
		ft_zoom_hook(ZOOM_IN, data);
	if (key.key == MLX_KEY_MINUS)
		ft_zoom_hook(ZOOM_OUT, data);
}

static void	ft_color_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_C)
	{
		data->r_shitf += CONST_COLOR;
		data->g_shitf += CONST_COLOR;
		data->b_shitf += CONST_COLOR;
	}
	if (key.key == MLX_KEY_R)
		data->r_shitf += CONST_COLOR;
	if (key.key == MLX_KEY_G)
		data->g_shitf += CONST_COLOR;
	if (key.key == MLX_KEY_B)
		data->b_shitf += CONST_COLOR;
	if (key.key == MLX_KEY_1)
		ft_reset_fractal(data);
	if (key.key == MLX_KEY_0)
	{
		ft_reset_fractal(data);
		data->r_shitf = 0.0;
	}
}
