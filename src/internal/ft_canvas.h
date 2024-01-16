/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_canvas.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:21:32 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 20:37:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CANVAS_H
# define FT_CANVAS_H

# include "ft_stdlib.h"
# include "ft_fractol.h"
# include "ft_control.h"
# include "ft_clean.h"
# include "ft_assets.h"
# include "ft_render.h"

void	ft_create_canvas(char **map);
void	ft_reset_fractal(t_canvas *data);

#endif
