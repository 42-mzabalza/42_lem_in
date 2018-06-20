/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_info_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:58:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:06:00 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		new_info_line(t_adjlist *adjlist, char *lne)
{
	char *tmp;

	if (!adjlist->info)
	{
		if (!(adjlist->info = ft_strdup(lne)))
			return (free_error(lne, NULL, 0));
		adjlist->info_i++;
		return (free_error(lne, NULL, 1));
	}
	tmp = adjlist->info;
	if (!(adjlist->info = ft_strjoin(adjlist->info, "\n")))
	{
		free(tmp);
		return (free_error(lne, NULL, 0));
	}
	free(tmp);
	tmp = adjlist->info;
	if (!(adjlist->info = ft_strjoin(adjlist->info, lne)))
	{
		free(tmp);
		return (free_error(lne, NULL, 0));
	}
	free(tmp);
	adjlist->info_i++;
	return (free_error(lne, NULL, 1));
}
