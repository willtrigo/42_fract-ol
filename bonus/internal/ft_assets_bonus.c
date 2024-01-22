/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:23:05 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:06:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_assets_bonus.h"

void	ft_load_assets(t_canvas_bonus *data)
{
	data->icon = mlx_load_png("./assets/42_icon.png");
}
