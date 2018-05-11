/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbdigits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 02:59:25 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/12 02:59:33 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_nbdigits(intmax_t nb)
{
	int			ndigits;
	uintmax_t	dstnb;

	dstnb = ft_abs(nb);
	ndigits = 1;
	while (dstnb >= 10)
	{
		dstnb /= 10;
		ndigits++;
	}
	return (ndigits);
}
