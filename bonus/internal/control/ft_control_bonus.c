/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:56:37 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:07:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/control/ft_control_bonus.h"

void	ft_key_hook(mlx_key_data_t key, t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_ESCAPE)
	{
		mlx_close_window(data->mlx);
		return ;
	}
	if (data->render == RENDER_ON)
		return ;
	ft_moviment_hook(key, data);
	ft_color_hook(key, data);
}

void	ft_scroll_hook(double xdelta, double ydelta, t_canvas_bonus *data)
{
	(void)xdelta;
	if (ydelta > 0.0 && !data->render)
	{
		ft_zoom_hook(ZOOM_IN, data);
		ft_zoom_offset(ZOOM_IN, data);
	}
	else if (ydelta < 0.0 && !data->render)
	{
		ft_zoom_hook(ZOOM_OUT, data);
		ft_zoom_offset(ZOOM_OUT, data);
	}
}
