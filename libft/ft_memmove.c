/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:51:42 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/16 22:24:39 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dstcpy;
	char	*srccpy;
	int		lencpy;

	dstcpy = (char *)dst;
	srccpy = (char *)src;
	lencpy = (int)len;
	if (dstcpy > srccpy)
	{
		while ((lencpy) > 0)
		{
			lencpy--;
			dstcpy[lencpy] = srccpy[lencpy];
		}
	}
	else
	{
		while (lencpy-- > 0)
			*dstcpy++ = *srccpy++;
	}
	return (dst);
}
