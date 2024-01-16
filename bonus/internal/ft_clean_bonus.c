/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:36:12 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:53:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_clean_bonus.h"

static void	ft_clean_fractal_assets(t_canvas_bonus *data);
static void	ft_clean_fractal_struct(t_canvas_bonus *data);

void	ft_clean(t_canvas_bonus *data)
{
	ft_clean_fractal_assets(data);
	ft_clean_fractal_struct(data);
	mlx_delete_image(data->mlx, data->canvas);
}

static void	ft_clean_fractal_assets(t_canvas_bonus *data)
{
	mlx_delete_texture(data->icon);
}

static void	ft_clean_fractal_struct(t_canvas_bonus *data)
{
	free(data->title_window);
	free(data->fractal);
	free(data->name);
}
