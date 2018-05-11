/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:23:54 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/30 23:33:49 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*scpy;
	char	ccpy;
	size_t	i;

	ccpy = (char)c;
	scpy = (char *)s;
	i = 0;
	while (i <= ft_strlen(s))
	{
		if (*scpy == ccpy)
		{
			return (scpy);
		}
		scpy++;
		i++;
	}
	return (NULL);
}
