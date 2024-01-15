/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:21:32 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:14:47 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVAS_BONUS_H
# define FT_CANVAS_BONUS_H

# include "ft_stdlib.h"
# include "ft_fractol_bonus.h"
# include "ft_control_bonus.h"
# include "ft_clean_bonus.h"
# include "ft_assets_bonus.h"
# include "ft_render_bonus.h"

void	ft_create_canvas(char **map);
void	ft_reset_fractal(t_canvas *data);

#endif
