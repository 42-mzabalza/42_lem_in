/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   goto_alist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 13:14:39 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/19 13:14:42 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist 	*pointer_2_glist(char *id_room, t_glist *tmp_glist)
{
	int i;

	if (!id_room)
		return (NULL);
	i = 0;
	while (tmp_glist)
	{
		if (!ft_strcmp(tmp_glist->head->id, id_room)) //mirar mi ft_strcmp!!!!
		{
			i++;
			break ;
		}
		tmp_glist = tmp_glist->next;
	}
	if (!i)
		return (NULL);
	return (tmp_glist);
}

/*
** findst the room tab0 in the alist, calls add node to add tab1 in that position
*/

int			goto_alist(char *tab0, char *tab1, t_glist *tmp_list, t_adjlist *alist)
{
	int i;

	i = 0;
	while (tmp_list)
	{
		if (!ft_strcmp(tmp_list->head->id, tab0)) //mirar mi ft_strcmp!!!!
		{
			i++;
			break ;
		}
		tmp_list = tmp_list->next;
	}
	if (!i)
		return (0);
	add_node(tab1, tmp_list, alist);
	return (1);
}

/*
**Adding nodes to lists. each node 1 glist
**Adding lists to the Adjacency list
*/

void		add_node(char *room, t_glist *glist, t_adjlist *alist)
{
	t_node	*node;
	t_glist *tmp_glist;

	node = init_node();
	if (!(node->id = ft_strdup(room)))
		exit (1);
	tmp_glist = pointer_2_glist(room, alist->start);
	node->passed = tmp_glist->head->passed;
	node->occupied = tmp_glist->head->occupied;
	node->x = tmp_glist->head->x;
	node->y = tmp_glist->head->y;
	node->next = NULL;
	node->prev = glist->tail;
	glist->tail->next = node;
	glist->tail = node;
}