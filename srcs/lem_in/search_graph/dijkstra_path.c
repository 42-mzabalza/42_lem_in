/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:36:25 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/11 15:39:02 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dijk	*init_dijk()

static t_dijk	*init_dijk(t_node *start)
{
	int 	i;
	t_path	*path;
	t_dijk	*global;
	char	*start_id;

	start_id = start->id;
	start = start->next;
	i = 0;
	(!(global = (t_dijk*)malloc(sizeof(t_dijk))))
			exit(-1);
	global->prev = NULL;
	while(start)
	{
		global->next = NULL;
		global->path_head = init_path(start_id);
		global->path_tail = add_node_2_path(global->path_head, path); //find free??
		if (!i)
		{
			global->d_head = global;
			i = 1;
		}
		start = start->next;
		global = 
		(!(global = (t_dijk*)malloc(sizeof(t_dijk))))
			exit(-1);
	}
}

t_path 			*dijkstra_path(t_adjlist *alist)
{
	t_path	*path;
	t_glist *g_tmp;
	t_dijk	*global;
	t_dijk	*global_head;

	global = init_dijk(alist->start->head);
	g_tmp = alist->start;
	path = init_path(g_tmp->head->id);
	final_path = path;
	if (!(g_tmp = pointer_2_glist(find_free_node(g_tmp->head), alist->start)))
	{
		ft_putstr("No path\n");
		exit(-1);
	}
	return (global_head);
}
