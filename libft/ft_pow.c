/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 20:11:58 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/22 19:01:55 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int power)
{
	int sol;
	int i;

	i = 1;
	sol = nb;
	if (power > 0)
		while (i++ < power)
			sol = sol * nb;
	else
	{
		if (power == 0)
			sol = 1;
		else
			sol = 0;
	}
	return (sol);
}
