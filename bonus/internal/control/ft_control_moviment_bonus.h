/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_moviment_bonus.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 06:48:11 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:53:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROL_MOVIMENT_BONUS_H
# define FT_CONTROL_MOVIMENT_BONUS_H

# include "ft_control_bonus.h"

void	ft_zoom_hook(uint8_t zoom_in_out, t_canvas_bonus *data);
void	ft_moviment_hook(mlx_key_data_t key, t_canvas_bonus *data);
void	ft_zoom_offset(int8_t zoom_in_out, t_canvas_bonus *data);

#endif
