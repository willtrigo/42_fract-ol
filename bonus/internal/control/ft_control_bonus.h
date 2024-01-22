/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:48:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:07:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROL_BONUS_H
# define FT_CONTROL_BONUS_H

# include "internal/ft_canvas_bonus.h"
# include "internal/control/ft_control_color_bonus.h"
# include "internal/control/ft_control_moviment_bonus.h"

void	ft_key_hook(mlx_key_data_t key, t_canvas_bonus *data);
void	ft_scroll_hook(double xdelta, double ydelta, t_canvas_bonus *data);

#endif
