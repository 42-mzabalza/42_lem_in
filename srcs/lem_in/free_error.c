/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:45:00 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 20:54:18 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_prev_list(t_prev *tail)
{
	t_prev *tmp;

	while (tail)
	{
		tmp = tail;
		tail = tail->prev;
		free(tmp);
	}
}

void	free_queue(t_stack *queue_head)
{
	t_stack *tmp;

	while (queue_head)
	{
		tmp = queue_head;
		queue_head = queue_head->next;
		free(tmp);
	}
}

void	free_adjlist(t_adjlist *adjlist)
{
	t_glist *tmp;

	while (adjlist->start)
	{
		tmp = adjlist->start;
		adjlist->start = adjlist->start->next;
		free_glist(tmp);
	}
	free(adjlist->info);
	free(adjlist);
}

int		free_alist_error(t_adjlist *alist, t_gpath *gpath, int out, char *str)
{
	if (!out)
	{
		ft_putendl(alist->info);
		ft_putchar('\n');
		show_answer(alist, gpath);
	}
	else
	{
		ft_putstr("ERROR");
		if (alist->flags & (1 << ('e' - 'a')))
		{
			if (!str)
			{
				ft_putstr(": line ");
				ft_putnbr(alist->info_i);
			}
			else
				ft_putstr(str);
		}
		ft_putchar('\n');
	}
	(alist) ? free_adjlist(alist) : 0;
	(gpath) ? free_map(gpath) : 0;
	return (out);
}

int		free_error(char *line, t_node *node, int out)
{
	if (line)
		free(line);
	if (node)
		free_node(node);
	return (out);
}
