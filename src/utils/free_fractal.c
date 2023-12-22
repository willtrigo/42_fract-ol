/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 09:36:12 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 00:36:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_free_fractal_assets(t_fractal *data)
{
	mlx_delete_texture(data->assets->t_icon);
}

void	ft_free_fractal_struct(t_fractal *data)
{
	free(data->assets);
	free(data->title_window);
}

void	ft_free_fractal(t_fractal *data)
{
	ft_free_fractal_assets(data);
	ft_free_fractal_struct(data);
}
