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

t_dijk	*zero_dijk(char *id)
{
	t_dijk	*global;

	if (!(global = (t_dijk*)malloc(sizeof(t_dijk))))
			exit(-1);
	global->prev = NULL;
	global->next = NULL;
	global->nb_nodes = 1;
	global->path_head = init_path(id);
	global->path_tail = global->path_head;
	return (global);
}

static t_dijk	*init_dijk(t_node *start, t_dijk **global_head, t_adjlist *alist)
{
	t_dijk	*global;
	char	*start_id;

	start_id = start->id;
	global = zero_dijk(start_id);
	*global_head = global;
	start = start->next;
	if (start)
	{
		global->path_tail = add_node_2_path(start->id, global->path_tail);
		global->glist = pointer_2_glist(global->path_tail->id, alist->start);
		global->nb_nodes++;
		*(global->glist->head->passed) = 1;
	}
	start = start->next;
	while (start)
	{
		global->next = zero_dijk(start_id); 
		global->next->prev = global;
		global = global->next;
		global->path_tail = add_node_2_path(start->id, global->path_tail); //find free??
		global->glist = pointer_2_glist(global->path_tail->id, alist->start);
		*(global->glist->head->passed) = 1;
		global->nb_nodes++;
		start = start->next;
	}
	return (global);
}

t_dijk			*dijkstra_path(t_adjlist *alist)
{
	t_dijk	*global;
	t_dijk	*global_head;
	// int i = 5000000;

	global = init_dijk(alist->start->head, &global_head, alist);
	//si el primero ya ha llegado al dos no me lo va a dar
	// while (global->glist->head->pos != 2)
	show_global_paths(global_head);
	ft_putendl("_________________________________________");
	// while (i--)
	while (global->glist->head->pos != 2)
	{
		if (!(global = find_shortest_gpath(global_head)))
		{
			ft_putendl("no paths");
			exit(1);
		}
		if (!(follow_shortest_path(global, alist)))
		{
			if (!remove_global(global, &global_head))
			{
				ft_putendl("no paths");
				exit(1);
			}
		}
	}
	show_global_paths(global_head);
	ft_putendl("_________________________________________");
	// ft_putendl("______shortest path______");
	// show_path(global->path_head);
	// ft_putendl("_________________________");
	return (global_head);
}
