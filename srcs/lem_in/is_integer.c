/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:28:29 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 20:58:32 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		is_integer(char *str)
{
	intmax_t nb;

	if (*str == '-' && ft_strlen(str) != 1)
		str++;
	if (*str == '+' && ft_strlen(str) != 1)
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 10)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	nb = ft_atointmax(str);
	if (nb > 2147483647 || nb < -2147483648)
		return (0);
	return (1);
}
