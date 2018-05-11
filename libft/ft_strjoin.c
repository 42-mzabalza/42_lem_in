/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 19:13:32 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 01:21:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*dst;

	if (s1 != NULL && s2 != NULL)
	{
		if (!(dst = (char *)malloc(sizeof(*dst) *
				(ft_strlen(s2) + (ft_strlen(s1) + 1)))))
			return (NULL);
		i = 0;
		while (*s1)
		{
			dst[i] = *s1;
			s1++;
			i++;
		}
		while (*s2)
		{
			dst[i] = *s2;
			s2++;
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
