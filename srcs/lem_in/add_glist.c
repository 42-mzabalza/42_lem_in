/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_glist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:59:26 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 20:41:21 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
** Adds one glist in the alist
*/

int		add_glist(t_node *node, t_adjlist *alist)
{
	t_glist *list;

	node->next = NULL;
	node->prev = NULL;
	if (!(list = (t_glist *)malloc(sizeof(t_glist))))
		return (0);
	list->head = node;
	list->tail = node;
	if (!(alist->nb_room))
	{
		alist->start = list;
		alist->end = list;
		list->next = NULL;
	}
	else
	{
		(alist->end)->next = list;
		list->next = NULL;
		alist->end = list;
	}
	alist->nb_room++;
	return (1);
}

int		add_connection(char *line, t_adjlist *alist)
{
	char	**tab;

	if (line[0] == '#')
		return (1);
	if (line_type(line, '-') != 1)
		return (0);
	if (!(tab = ft_strsplit(line, '-')))
		return (0);
	if (!ft_strcmp(tab[0], tab[1]))
	{
		free_tab(tab);
		return (0);
	}
	if (!goto_alist(tab[0], tab[1], alist->start, alist))
	{
		free_tab(tab);
		return (0);
	}
	if (!goto_alist(tab[1], tab[0], alist->start, alist))
	{
		free_tab(tab);
		return (0);
	}
	free_tab(tab);
	return (1);
}
