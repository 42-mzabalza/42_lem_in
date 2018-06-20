/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 14:56:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/20 22:16:56 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	skip_comments(char **line, t_adjlist *adjlist)
{
	while (*line[0] == '#')
	{
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
			return (free_error(*line, NULL, 0));
		if (!new_info_line(adjlist, *line))
			return (0);
		if (get_next_line(0, line) <= 0)
			return (0);
	}
	return (1);
}

static int	check_firstline(char *line, t_adjlist *adjlist)
{
	if (!adjlist->info)
	{
		if (!(adjlist->info = ft_strdup(line)))
			return (free_error(line, NULL, 0));
		free(line);
		adjlist->info_i++;
	}
	else
	{
		if (!new_info_line(adjlist, line))
			return (0);
	}
	return (1);
}

int			get_nb_ants(t_adjlist *adjlist)
{
	char		*line;
	int			i;
	intmax_t	nb_ants;

	if (get_next_line(0, &line) > 0)
	{
		if (!skip_comments(&line, adjlist))
			return (0);
		if (ft_isnum(line) != 1)
			return (free_error(line, NULL, 0));
		nb_ants = ft_atointmax(line);
		if (!check_firstline(line, adjlist))
			return (0);
		if (nb_ants > 2147483647 || !nb_ants)
			return (0);
	}
	else
		return (0);
	return (nb_ants);
}
