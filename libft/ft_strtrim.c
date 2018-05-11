/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:27:58 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:30:50 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		nsp1;
	int		nsp2;
	int		i;
	char	*dst;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
		return ("");
	nsp1 = 0;
	while (s[nsp1] == ' ' || s[nsp1] == '\n' || s[nsp1] == '\t')
	{
		nsp1++;
		if (s[nsp1] == 0)
			return (ft_strnew(1));
	}
	nsp2 = ft_strlen(s) - 1;
	while (s[nsp2] == ' ' || s[nsp2] == '\n' || s[nsp2] == '\t')
		nsp2--;
	if (!(dst = ft_strnew((size_t)(nsp2 - nsp1 + 1))))
		return (NULL);
	i = 0;
	while (nsp1 <= nsp2)
		dst[i++] = s[nsp1++];
	return (dst);
}
