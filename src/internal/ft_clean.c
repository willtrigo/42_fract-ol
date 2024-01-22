/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:36:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 08:50:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_clean.h"

static void	ft_clean_fractal_assets(t_canvas *data);
static void	ft_clean_fractal_struct(t_canvas *data);

void	ft_clean(t_canvas *data)
{
	ft_clean_fractal_assets(data);
	ft_clean_fractal_struct(data);
	mlx_delete_image(data->mlx, data->canvas);
}

static void	ft_clean_fractal_assets(t_canvas *data)
{
	mlx_delete_texture(data->icon);
}

static void	ft_clean_fractal_struct(t_canvas *data)
{
	free(data->title_window);
	free(data->fractal);
	free(data->name);
}
