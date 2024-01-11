/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:56:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 08:59:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control_bonus.h"

static void	ft_color_hook(mlx_key_data_t key, t_canvas *data);

void	ft_key_hook(mlx_key_data_t key, t_canvas *data)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
	if (key.key == MLX_KEY_RIGHT)
		data->fractal->offset.x += data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_LEFT)
		data->fractal->offset.x -= data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_UP)
		data->fractal->offset.y += data->fractal->zoom.x / 30.0;
	if (key.key == MLX_KEY_DOWN)
		data->fractal->offset.y -= data->fractal->zoom.x / 30.0;
	ft_color_hook(key, data);
	ft_render_fractal(data);
}

void	ft_scroll_hook(double xdelta, double ydelta, t_canvas *data)
{
	(void)xdelta;
	if (ydelta > 0.0)
	{
		data->fractal->zoom.x -= data->fractal->zoom.x / SPEED * 2;
		data->fractal->zoom.y -= data->fractal->zoom.y / SPEED * 2;
	}
	else if (ydelta < 0.0)
	{
		data->fractal->zoom.x += data->fractal->zoom.x / SPEED;
		data->fractal->zoom.y += data->fractal->zoom.y / SPEED;
	}
	if (data->fractal->zoom.x > ZOOM_INIT)
	{
		data->fractal->zoom.x = ZOOM_INIT;
		data->fractal->zoom.y = ZOOM_INIT;
		data->fractal->offset.x = 0.0;
		data->fractal->offset.y = 0.0;
	}
	ft_render_fractal(data);
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
