/* *********cat ***************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_glist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:59:26 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 16:59:31 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// Any unknown command will be ignored

t_adjlist	*init_adjlist()
{
	t_adjlist *adjlist;

	adjlist = (t_adjlist *)malloc(sizeof(t_adjlist));
	adjlist->nb_room = 0;
	adjlist->nb_ant = 0;
	adjlist->start = NULL;
	adjlist->end = NULL;
	return (adjlist);
}

/*
** Adds one glist in the alist
*/

void		add_glist(t_node *node, t_adjlist *alist)
{
	t_glist *list;

	node->next = NULL;
	node->prev = NULL;
	if (!(list = (t_glist *)malloc(sizeof(t_glist))))
		exit(1);
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
}

int			add_connection(char *line, t_adjlist *alist)
{
	char	**tab;
	
	if (line_type(line, '#') == 1)
		return (1);
	if (line_type(line, '-') != 1)
		return (0);
	tab = ft_strsplit(line, '-'); //si tengo un argumento? hacer un checker mejor
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
	free_tab(tab); //free de lo que esta dentro del tab tambien//free_split
	return (1);
}
