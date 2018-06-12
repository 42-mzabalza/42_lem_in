/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <mzabalza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:10:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/12 13:28:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_prev_list(t_prev *tail)
{
	t_prev *tmp;
	
	while(tail)
	{
		tmp = tail;
		tail = tail->prev;
		free(tmp);
	}
}

void 	free_queue(t_stack *queue_head)
{
	t_stack *tmp;

	while(queue_head)
	{
		tmp = queue_head;
		queue_head = queue_head->next;
		free(tmp);
	}
}

void	free_map(t_gpath *gpath)
{
	t_path 	*tmp_path;
	t_gpath	*tmp_gpath;

	while(gpath)
	{
		tmp_gpath = gpath;
		while(gpath->path_head)
		{
			tmp_path = gpath->path_head;
			gpath->path_head = gpath->path_head->next;
			free(tmp_path);
		}
		gpath = gpath->next;
		free(tmp_gpath);
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_node(t_node *node)
{
	free(node->occupied);
	free(node->passed);
	free(node->id);
	free(node);
}

void	free_glist(t_glist *glist)
{
	t_node *tmp;

	tmp = glist->head;
	glist->head= glist->head->next;
	free_node(tmp);
	while (glist->head)
	{
		tmp = glist->head;
		glist->head= glist->head->next;
		free(tmp->id);
		free(tmp);
	}
	free(glist);
}

void	free_adjlist(t_adjlist *adjlist)
{
	t_glist *tmp;

	while(adjlist->start)
	{
		tmp = adjlist->start;
		adjlist->start = adjlist->start->next;
		free_glist(tmp);
	}
	free(adjlist->info);
	free(adjlist);
}