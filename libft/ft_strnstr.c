/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 23:09:18 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 01:14:07 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (*haystack)
	{
		if ((i) + ft_strlen(needle) > len)
			return (NULL);
		if (ft_strncmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
