/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:38:15 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:09:36 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char ccpy;
	unsigned char *bcpy;

	ccpy = (unsigned char)c;
	bcpy = (unsigned char *)b;
	while (len-- > 0)
	{
		*bcpy = ccpy;
		bcpy++;
	}
	return (b);
}
