/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_fractal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:36:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/08 00:58:14 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

static void	ft_free_fractal_assets(t_canvas *data)
{
	mlx_delete_texture(data->icon);
}

static void	ft_free_fractal_struct(t_canvas *data)
{
	free(data->title_window);
	free(data->fractal);
	free(data->name);
}

void	ft_free_fractal(t_canvas *data)
{
	ft_free_fractal_assets(data);
	ft_free_fractal_struct(data);
}
