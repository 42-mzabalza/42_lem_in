/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 01:12:22 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:28:58 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dst;

	if (s != NULL)
	{
		dst = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!dst)
			return (NULL);
		i = 0;
		while (s[i])
		{
			dst[i] = f(s[i]);
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
