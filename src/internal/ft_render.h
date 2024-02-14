/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:45:53 by dande-je          #+#    #+#             */
/*   Updated: 2024/02/13 21:47:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_H
# define FT_RENDER_H

# include "MLX42/MLX42.h"
# include "ft_fractol.h"
# include "internal/ft_color.h"
# include "internal/ft_math.h"
# include "internal/ft_utils.h"

void	ft_render_fractal(t_canvas *data);
void	ft_handle_time(void *param);

#endif
