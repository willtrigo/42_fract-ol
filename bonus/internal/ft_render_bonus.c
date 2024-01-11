/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 08:10:15 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/11 06:28:20 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_render_bonus.h"

static void	ft_handle_pixel(int x, int y, t_canvas *data);

void	ft_render_fractal(t_canvas *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			ft_handle_pixel(x, y, data);
	}
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
		z = ft_sum_complex(ft_square_complex(z), c);
		if (z.x * z.x + z.y * z.y > MAX_VALUE_POLY)
		{
			mlx_put_pixel(data->canvas, x, y, ft_bernstein_poly(i, 0xFF, data));
			return ;
		}
	}
	mlx_put_pixel(data->canvas, x, y, ft_color(0x00, 0x00, 0x00, 0xFF).value);
}
