/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:43:35 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:11:03 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *scpy;

	scpy = (unsigned char *)s;
	while (n--)
	{
		if (*scpy == ((unsigned char)c))
			return (scpy);
		scpy++;
	}
	return (NULL);
}
