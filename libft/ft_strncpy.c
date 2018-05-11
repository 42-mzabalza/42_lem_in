/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:31:54 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/16 22:31:05 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t l;

	l = len;
	i = 0;
	while (len > 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len-- > 0)
		dst[i++] = '\0';
	return (dst);
}
