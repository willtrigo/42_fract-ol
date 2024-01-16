/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:23:05 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:53:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_assets_bonus.h"

void	ft_load_assets(t_canvas_bonus *data)
{
	data->icon = mlx_load_png("./assets/42_icon.png");
}
