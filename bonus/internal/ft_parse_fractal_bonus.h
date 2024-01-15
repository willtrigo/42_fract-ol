/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fractal_bonus.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 05:39:21 by dande-je          #+#    #+#             */
/*   Updated: 2024/01/15 08:59:56 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_FRACTAL_BONUS_H
# define FT_PARSE_FRACTAL_BONUS_H

# include <errno.h>
# include "MLX42/MLX42.h"
# include "ft_non_standard.h"
# include "ft_string.h"
# include "ft_canvas_bonus.h"
# include "ft_utils_bonus.h"

void	ft_parse_fractal(int32_t argc, char **map);
void	ft_set_julia(t_complex *c, t_canvas *data);

#endif
