/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:45:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/09 06:10:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "MLX42/MLX42.h"
# include "ft_fractol.h"
# include "ft_canvas.h"
# include "ft_color.h"
# include "ft_math.h"

void	ft_render_fractal(t_canvas *data);
void	ft_render_bg(t_canvas *data);

#endif
