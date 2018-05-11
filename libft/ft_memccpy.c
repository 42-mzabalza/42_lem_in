/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:47:03 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 01:58:43 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dstcpy;
	unsigned char		*srccpy;

	dstcpy = (unsigned char *)dst;
	srccpy = (unsigned char *)src;
	while (n--)
	{
		if (*srccpy == (unsigned char)c)
		{
			*dstcpy++ = *srccpy++;
			return ((void*)dstcpy);
		}
		*dstcpy++ = *srccpy++;
	}
	return (NULL);
}
