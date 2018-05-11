/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 00:12:08 by mzabalza          #+#    #+#             */
/*   Updated: 2018/03/06 01:11:01 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	ft_atointmax(const char *str)
{
	int			i;
	int			sign;
	intmax_t	sol;

	if (str == NULL)
		return (0);
	sign = 1;
	i = 0;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	sol = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		sol = (sol * 10) + (str[i] - 48);
		i++;
	}
	return (sol * sign);
}
