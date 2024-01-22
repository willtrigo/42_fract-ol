/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:48:51 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 08:49:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTROL_H
# define FT_CONTROL_H

# include "internal/ft_canvas.h"

void	ft_key_hook(mlx_key_data_t key, t_canvas *data);
void	ft_scroll_hook(double xdelta, double ydelta, t_canvas *data);

#endif
