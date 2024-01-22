/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:21:32 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/22 09:06:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVAS_BONUS_H
# define FT_CANVAS_BONUS_H

# include "ft_stdlib.h"
# include "ft_fractol_bonus.h"
# include "internal/control/ft_control_bonus.h"
# include "internal/ft_clean_bonus.h"
# include "internal/ft_assets_bonus.h"
# include "internal/ft_render_bonus.h"

void	ft_create_canvas(char **map);
void	ft_reset_fractal(t_canvas_bonus *data);

#endif
