/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:45:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 22:09:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_BONUS_H
# define FT_RENDER_BONUS_H

# include "ft_fractol_bonus.h"
# include "internal/ft_color_bonus.h"
# include "internal/ft_math_bonus.h"
# include "internal/ft_utils_bonus.h"

void	ft_render_fractal(t_canvas_bonus *data);
void	ft_handle_time(void *param);

#endif
