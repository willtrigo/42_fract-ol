/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:23:05 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 08:52:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_assets.h"

void	ft_load_assets(t_canvas *data)
{
	data->icon = mlx_load_png("./assets/42_icon.png");
}
