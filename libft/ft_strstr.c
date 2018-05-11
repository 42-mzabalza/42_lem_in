/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 21:22:02 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 01:13:20 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *h;

	h = (char *)haystack;
	if (ft_strlen(needle) == 0)
		return (h);
	while (*h)
	{
		if (ft_strncmp(h, needle, ft_strlen(needle)) == 0)
			return ((char *)h);
		h++;
	}
	return (NULL);
}
