/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:54:49 by dande-je          #+#    #+#             */
/*   Updated: 2023/12/18 19:15:03 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_fractol.h"

int	ft_is_valid_double(const char *str)
{
	char	*endptr;

	strtod(str, &endptr);
	return (*endptr == '\0');
}
