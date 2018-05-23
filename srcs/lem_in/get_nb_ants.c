/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:56:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/23 14:56:49 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			get_nb_ants()
{
	char	*line;
	int 	i;
	int		nb_ants;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_isnum(line) != 1)
		{
			free(line);
			return (0);
		}
		nb_ants = ft_atoi(line);
		free(line);
	}
	return (nb_ants);
}
