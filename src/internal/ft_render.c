/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:10:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/15 18:51:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_render.h"

static void	ft_handle_pixel(int x, int y, t_canvas *data);

void	ft_handle_time(void *param)
{
	t_canvas	*data;

	data = (t_canvas *)param;
	if (mlx_get_time() > data->delay)
		data->render = RENDER_OFF;
}

void	ft_render_fractal(t_canvas *data)
{
	int	x;
	int	y;

	y = -1;
	data->delay = mlx_get_time() + DELAY * 100;
	data->render = RENDER_ON;
	data->canvas = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, data);
	}
	mlx_image_to_window(data->mlx, data->canvas, 0, 0);
	data->delay = mlx_get_time() + DELAY;
}

static void	ft_handle_pixel(int x, int y, t_canvas *data)
{
	t_complex	z;
	t_complex	c;
	t_complex	x_y;
	int32_t		i;

	i = -1;
	x_y.x = x;
	x_y.y = y;
	ft_get_complex(data, &z, &c, &x_y);
	while (++i < MAX_DEFINITION)
	{
		z = ft_sum_complex(ft_square_z_complex(z, MAX), c);
		if (z.x * z.x + z.y * z.y > MAX_VALUE_POLY)
		{
			mlx_put_pixel(data->canvas, x, y, ft_bernstein_poly(i, 0xFF, data));
			break ;
		}
	}
	mlx_put_pixel(data->canvas, x, y, ft_bernstein_poly(i, 0xFF, data));
}
