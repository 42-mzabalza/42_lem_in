/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breath_first_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:20:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:26:36 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		neigh(t_stack **hd, t_stack **tl, t_prev **pv, t_glist *g_strt)
{
	t_node *neighbors;

	neighbors = (*hd)->glist->head->next;
	while (neighbors)
	{
		if (!(*(neighbors->passed)))
		{
			add_2_queue(tl, pointer_2_glist(neighbors->id, g_strt));
			add_2_prev(pv, neighbors->id, (*hd)->glist->head->id);
			if ((*tl)->glist->head->pos == 2)
				return (1);
		}
		neighbors = neighbors->next;
	}
	if (!rm_from_queue(hd))
		return (-1);
	return (0);
}

static t_stack	*init_queue(t_glist *glist)
{
	t_stack	*queue;

	queue = (t_stack *)malloc(sizeof(t_stack));
	queue->glist = glist;
	queue->next = NULL;
	return (queue);
}

static t_prev	*init_previous(t_glist *glist)
{
	t_prev	*previous;

	previous = (t_prev *)malloc(sizeof(t_prev));
	previous->current = glist->head->id;
	previous->previous = NULL;
	previous->prev = NULL;
	previous->next = NULL;
	return (previous);
}

t_prev			*breath_first_search(t_glist *glist_start)
{
	t_stack		*queue_head;
	t_stack		*queue_tail;
	t_prev		*previous;
	int			rtn;

	previous = init_previous(find_start(glist_start));
	queue_tail = init_queue(find_start(glist_start));
	queue_head = queue_tail;
	while (queue_head->glist->head->pos != 2)
	{
		rtn = neigh(&queue_head, &queue_tail, &previous, glist_start);
		if (rtn == 1)
		{
			free_queue(queue_head);
			return (previous);
		}
		else if (rtn == -1)
		{
			free_prev_list(previous);
			free_queue(queue_head);
			return (NULL);
		}
	}
	free_queue(queue_head);
	return (previous);
}
