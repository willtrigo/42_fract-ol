/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:45:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/10 08:47:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_BONUS_H
# define FT_RENDER_BONUS_H

# include "MLX42/MLX42.h"
# include "ft_fractol_bonus.h"
# include "ft_canvas_bonus.h"
# include "ft_color_bonus.h"
# include "ft_math_bonus.h"

void	ft_render_fractal(t_canvas *data);
void	ft_render_bg(t_canvas *data);

#endif
