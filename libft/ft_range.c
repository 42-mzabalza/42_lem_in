/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:10:53 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/22 20:25:59 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_range(int min, int max)
{
	int i;
	int *range;

	if (min >= max)
		return (NULL);
	range = malloc(sizeof(int) * ((max - min) + 2));
	if (!range)
		return (NULL);
	i = 0;
	while (i < (max - min + 1))
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
