/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager_fractol.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 19:16:03 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/18 20:20:40 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_FRACTOL_H
# define MANAGER_FRACTOL_H

# include "ft_fractol.h"

typedef struct s_fractol	t_fractol;
struct s_fractol
{
	mlx_t	*mlx;
};

void	ft_init_fractol(int32_t argc, char **map);
int		ft_is_valid_double(const char *str);
void	ft_parse_julia(char **map);
void	ft_parse_mandelbrot(int32_t argc);
void	ft_create_fractol(char **map);

#endif
