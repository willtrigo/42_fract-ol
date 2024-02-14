/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:10:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/14 01:42:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_render_bonus.h"

static void	ft_handle_pixel(int x, int y, t_canvas_bonus *data);

void	ft_handle_time(void *param)
{
	t_canvas_bonus	*data;

	data = (t_canvas_bonus *)param;
	data->chronometer += mlx_get_time();
	if (data->chronometer > DELAY)
		data->render = RENDER_OFF;
}

void	ft_render_fractal(t_canvas_bonus *data)
{
	int	x;
	int	y;

	y = -1;
	data->render = RENDER_ON;
	data->canvas = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, data);
	}
	mlx_image_to_window(data->mlx, data->canvas, 0, 0);
	data->chronometer = 0.0;
}

static void	ft_handle_pixel(int x, int y, t_canvas_bonus *data)
{
	t_complex_bonus	z;
	t_complex_bonus	c;
	t_complex_bonus	x_y;
	int32_t			i;

	i = -1;
	x_y.x = x;
	x_y.y = y;
	ft_get_complex(data, &z, &c, &x_y);
	while (++i < MAX_DEFINITION)
	{
		if (!ft_strncmp(data->name, "tricorn", ft_str_len("tricorn")))
			z = ft_sum_complex(ft_square_z_complex(z, MIN), c);
		else
			z = ft_sum_complex(ft_square_z_complex(z, MAX), c);
		if (z.x * z.x + z.y * z.y > MAX_VALUE_POLY)
		{
			mlx_put_pixel(data->canvas, x, y, ft_bernstein_poly(i, 0xFF, data));
			break ;
		}
	}
	mlx_put_pixel(data->canvas, x, y, ft_bernstein_poly(i, 0xFF, data));
}
