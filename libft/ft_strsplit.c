/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 22:44:15 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 19:30:59 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nletts(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static	size_t		ft_nwords(char const *s, char c)
{
	size_t words;
	size_t i;
	size_t len;

	words = 0;
	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			words++;
		i++;
	}
	return (words);
}

char				**ft_strsplit(char const *s, char c)
{
	size_t			i;
	size_t			j;
	size_t			words;
	char			**dst;

	if (s == NULL)
		return (NULL);
	words = ft_nwords(s, c);
	if (!(dst = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	while (i < words)
	{
		j = 0;
		while (*s == c)
			s++;
		if (!(dst[i] = (char *)malloc(sizeof(char) * (ft_nletts(s, c) + 1))))
			return (NULL);
		while (*s && *s != c)
			dst[i][j++] = *s++;
		dst[i][j] = '\0';
		i++;
	}
	dst[i] = NULL;
	return (dst);
}
