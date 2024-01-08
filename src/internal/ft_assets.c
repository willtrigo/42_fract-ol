/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_fractal_assets.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:23:05 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/22 13:56:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

void	ft_load_assets(t_canvas *data)
{
	data->icon = mlx_load_png("./assets/42_icon.png");
}
