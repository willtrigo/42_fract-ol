/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:35:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:04:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_math_bonus.h"

void	ft_get_complex(t_canvas_bonus *data, t_complex_bonus *z, \
			t_complex_bonus *c, t_complex_bonus *x_y)
{
	if (!ft_strncmp(data->name, "mandelbrot", ft_str_len("mandelbrot")))
		z->x = (ft_get_z_complex(x_y->x - (WIDTH / 3) - 17, MIN, MAX, HEIGHT) \
			* data->fractal->zoom.x) + data->fractal->offset.x;
	else
		z->x = (ft_get_z_complex(x_y->x - (WIDTH / 4), MIN, MAX, HEIGHT) \
			* data->fractal->zoom.x) + data->fractal->offset.x;
	z->y = (ft_get_z_complex(x_y->y, MAX, MIN, HEIGHT) \
		* data->fractal->zoom.y) + data->fractal->offset.y;
	c->x = z->x;
	c->y = z->y;
	if (!ft_strncmp(data->name, "julia", ft_str_len("julia")))
	{
		c->x = data->fractal->c.x;
		c->y = data->fractal->c.y;
	}
}

double	ft_get_z_complex(double offset, double min, double max, double size)
{
	return ((max - min) * (offset - 0) / (size - 0) + min);
}

t_complex_bonus	ft_sum_complex(t_complex_bonus z, t_complex_bonus c)
{
	t_complex_bonus	sum_complex;

	sum_complex.x = z.x + c.x;
	sum_complex.y = z.y + c.y;
	return (sum_complex);
}

t_complex_bonus	ft_square_z_complex(t_complex_bonus z, double value)
{
	t_complex_bonus	square_z;

	square_z.x = (z.x * z.x) - (z.y * z.y);
	square_z.y = value * z.x * z.y;
	return (square_z);
}
