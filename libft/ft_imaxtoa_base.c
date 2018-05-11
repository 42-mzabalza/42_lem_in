/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:15:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/02/03 15:49:53 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_ndigits(intmax_t nb, unsigned int base)
{
	int digits;

	digits = 1;
	while (nb >= base)
	{
		nb /= base;
		digits++;
	}
	return (digits);
}

char		*ft_imaxtoa_base(intmax_t nb, int base)
{
	int		ndigits;
	char	*dst;
	int		remain;

	ndigits = ft_ndigits(nb, base);
	dst = (char *)malloc(sizeof(char) * (ndigits + 1));
	dst[ndigits] = '\0';
	while (ndigits-- > 0)
	{
		remain = nb % base;
		if (remain > 9)
			remain = remain - 10 + 'a';
		else
			remain = remain + '0';
		dst[ndigits] = remain;
		nb /= base;
	}
	return (dst);
}
