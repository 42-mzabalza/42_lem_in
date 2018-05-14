/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_shortest_gpath.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:31:42 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/14 18:31:44 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_dijk	*add_cpy_gpath(t_dijk *global)
{
	t_dijk	*new_global;
	t_path	*tmp_path;

	new_global = zero_dijk(global->path_head->id);
	new_global->nb_nodes = global->nb_nodes;
	new_global->glist = global->glist;
	tmp_path = global->path_head;
	while (tmp_path->next)
	{
		new_global->path_tail = add_node_2_path(tmp_path->next->id, new_global->path_tail);
		tmp_path = tmp_path->next;
	}
	new_global->next = global->next;
	global->next = new_global;
	new_global->prev = global;
	return (new_global);

}

static		 pointer_2_free_node(t_node *list)
{
	while (list)
	{
		if (*(list->passed) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

void		follow_shortest_path(t_dijk *global)
{
	int 	i;
	t_node	*tmp_list;

	i = 0;
	tmp_list = global->glist->head->next;
	while (tmp_list)
	{
		if (*(tmp_list->passed == 0))
		{
			add_node_2_path(tmp_list->id, global->path_tail);
			*(tmp_list->passed) = 1;
			global->nb_nodes++;
		}
		if (tmp_list = pointer_2_free_node(tmp_list))
			global = add_cpy_gpath(global);
		tmp_list = tmp_list->next;
	}
}

t_global	*find_shortest_gpath(t_global *global_paths)
{
	t_global	*shortest_gpath;

	shortest_gpath = global_paths;
	while (global_paths)
	{
		if (global_paths->nb_nodes < shortest_gpath->nb_nodes)
			shortes_gpath = global_paths;
		global_paths = global_paths->next;
	}
	return (shortest_gpath);
}