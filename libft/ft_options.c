/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 18:43:18 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/20 16:27:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_options(int ac, char **av)
{
	int i;
	int j;
	int rtn;

	rtn = 0;
	i = 1;
	while (av[i] && av[i][0] == '-')
	{
		j = 1;
		while (av[i][j])
		{
			if (ft_isalpha(av[i][j]) && av[i][j] > 96)
				rtn |= 1 << (av[i][j] - 'a');
			j++;
		}
		i++;
	}
	i = ac;
	return (rtn);
}
