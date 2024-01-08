/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 21:35:10 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 00:45:22 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_get_complex(t_canvas *data, t_complex *z, t_complex *c,
			t_complex *x_y)
{
	z->x = (ft_get_z_complex(x_y->x - (WIDTH / 4), MIN, MAX, HEIGHT) \
		* data->fractal->zoom.x) + data->fractal->offset.x;
	z->y = (ft_get_z_complex(x_y->y + (HEIGHT / 20), MAX, MIN, HEIGHT) \
		* data->fractal->zoom.y) + data->fractal->offset.y;
	c->x = z->x;
	c->y = z->y;
	if (!ft_strncmp(data->name, "julia", ft_str_len("julia")))
		ft_set_julia(c, data);
}

double	ft_get_z_complex(double offset, double min, double max, double zoom)
{
	return ((max - min) * (offset - 0) / (zoom - 0) + min);
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = MAX * z.x * z.y;
	return (res);
}
