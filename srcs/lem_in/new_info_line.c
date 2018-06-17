/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_info_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:58:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/12 15:58:14 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	new_info_line(t_adjlist *adjlist, char *line)
{
	char *tmp;

	tmp = adjlist->info;
	if (!(adjlist->info = ft_strjoin(adjlist->info, "\n")))
		return (0);
	free(tmp);
	tmp = adjlist->info;
	if (!(adjlist->info = NULL))
	{
		line = NULL;
		return (0);
	}
	free(tmp);
	adjlist->info_i++;
	free(line);
	return (1);
}