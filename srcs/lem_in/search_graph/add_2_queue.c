/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_2_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 16:05:27 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/17 16:06:34 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void 	add_2_prev(t_prev **prev, char *current, char *previous)
{
	t_prev *prev_node;

	prev_node = (t_prev *)malloc(sizeof(t_prev));
	prev_node->current = current;
	prev_node->previous = previous;
	prev_node->next = NULL;
	prev_node->prev = *prev;
	(*prev)->next = prev_node;
	*prev = prev_node;
}

int	rm_from_queue(t_stack **queue_head)
{
	t_stack *tmp;
	
	tmp = *queue_head;
	*queue_head = (*queue_head)->next;
	if (!(*queue_head))
		return (0);
	// free(tmp);
	return (1);
}
	

void	add_2_queue(t_stack **queue_tail, t_glist *glist)
{
	t_stack *new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	*(glist->head->passed) = 1;
	new_node->glist = glist;
	new_node->next = NULL;
	(*queue_tail)->next = new_node;
	*queue_tail = new_node;
}
