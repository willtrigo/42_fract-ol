/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:56:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:49:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_control_bonus.h"

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
