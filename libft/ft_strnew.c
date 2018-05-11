/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 00:28:00 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:26:24 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;

	dst = malloc(sizeof(char) * (size + 1));
	if (dst == 0)
		return (NULL);
	ft_bzero(dst, size + 1);
	return (dst);
}
