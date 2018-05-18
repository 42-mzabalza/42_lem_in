/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breath_first_search.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 12:20:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/17 12:44:11 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		explore_neigh(t_stack **q_head, t_stack **q_tail, t_prev **prev, t_glist *glist_start)
{
	t_node *neighbors;

	neighbors = (*q_head)->glist->head->next;
	// show_nodes(neighbors);
	while (neighbors)
	{
		if (!(*(neighbors->passed)))
		{
			add_2_queue(q_tail, pointer_2_glist(neighbors->id, glist_start));
			add_2_prev(prev, neighbors->id, (*q_head)->glist->head->id);
			if ((*q_tail)->glist->head->pos == 2)
				return (1);
		}
		neighbors = neighbors->next;
	}
	if (!rm_from_queue(q_head))
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
	int 		rtn;
	// int i = 4;

	previous = init_previous(find_start(glist_start));
	queue_tail = init_queue(find_start(glist_start));
	queue_head = queue_tail;
	// show_prev_list(previous);
	while (queue_head->glist->head->pos != 2)
	// while(i--)
	{
		rtn = explore_neigh(&queue_head, &queue_tail, &previous, glist_start);
		if (rtn == 1)
			return (previous);
		else if (rtn == -1)
			return(NULL);
		// show_prev_list(previous);
		// show_queue(queue_head);
	}
	// show_prev_list(previous);//
	return (previous);
}