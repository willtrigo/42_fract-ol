/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_color_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 05:26:04 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/15 18:54:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/control/ft_control_color_bonus.h"

static void	ft_change_all_color_channel(mlx_key_data_t key, \
	t_canvas_bonus *data);
static void	ft_change_color_channel(mlx_key_data_t key, t_canvas_bonus *data);
static void	ft_reset_color(mlx_key_data_t key, t_canvas_bonus *data);

void	ft_color_hook(mlx_key_data_t key, t_canvas_bonus *data)
{
	ft_change_all_color_channel(key, data);
	ft_change_color_channel(key, data);
	ft_reset_color(key, data);
}

static void	ft_change_all_color_channel(mlx_key_data_t key, \
	t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_C && !data->render)
	{
		data->delay = mlx_get_time() + DELAY * 100;
		data->render = RENDER_ON;
		data->r_shitf += CONST_COLOR;
		data->g_shitf += CONST_COLOR;
		data->b_shitf += CONST_COLOR;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}

static void	ft_change_color_channel(mlx_key_data_t key, t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_R && !data->render)
	{
		data->delay = mlx_get_time() + DELAY * 100;
		data->render = RENDER_ON;
		data->r_shitf += CONST_COLOR;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_G && !data->render)
	{
		data->delay = mlx_get_time() + DELAY * 100;
		data->render = RENDER_ON;
		data->g_shitf += CONST_COLOR;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_B && !data->render)
	{
		data->delay = mlx_get_time() + DELAY * 100;
		data->render = RENDER_ON;
		data->b_shitf += CONST_COLOR;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}

static void	ft_reset_color(mlx_key_data_t key, t_canvas_bonus *data)
{
	if (key.key == MLX_KEY_1 && !data->render)
	{
		ft_reset_fractal(data);
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
	if (key.key == MLX_KEY_0 && !data->render)
	{
		ft_reset_fractal(data);
		data->r_shitf = 0.0;
		data->b_shitf = 0.0;
		data->g_shitf = 0.0;
		mlx_delete_image(data->mlx, data->canvas);
		ft_render_fractal(data);
	}
}
