/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_queue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 11:12:16 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/18 11:12:58 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_prev	*find_previous(char *id, t_prev *tail)
{
	if (!id)
		return (NULL);
	while(tail)
	{
		if (!ft_strcmp(tail->current, id))
			return (tail);
		tail = tail->prev;
	}
	return (NULL);
}

void			show_prev_list(t_prev *prev_list)
{
	t_prev	*tail;

	tail = prev_list;
	while(prev_list)
	{
		ft_putendl(prev_list->current);
		prev_list = find_previous(prev_list->previous, tail);
	}
}

void		show_queue(t_stack *queue_head)
{
	ft_putendl("-----queue start-----");
	while(queue_head)
	{
		ft_putendl(queue_head->glist->head->id);
		queue_head = queue_head->next;
	}
	ft_putendl("-----queue end-----");

}
