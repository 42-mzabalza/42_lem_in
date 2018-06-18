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

	if (line[0] == '#' && ft_strcmp(line, "##start") && ft_strcmp(line, "##end"))
	{
		adjlist->info_i++;
		free(line);
		return (1);
	}
	tmp = adjlist->info;
	if (!(adjlist->info = ft_strjoin(adjlist->info, "\n")))
	{
		free(tmp);
		return(free_error(line, NULL, 0));
	}
	free(tmp);
	tmp = adjlist->info;
	if (!(adjlist->info = ft_strjoin(adjlist->info, line)))
	{
		free(tmp);
		return(free_error(line, NULL, 0));
	}
	free(tmp);
	adjlist->info_i++;
	free(line);
	return (1);
}