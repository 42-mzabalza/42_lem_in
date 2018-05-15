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

t_dijk			*remove_global(t_dijk *global, t_dijk **global_head)
{	
	if (!global->prev && !global->next)
		return (0); //habria que hacer free antes
	if (!global->prev && global->next)
		*global_head = global->next;
	if (global->prev)
		global->prev->next = global->next;
	if (global->next)
		global->next->prev = global->prev;
	// free(global);
	//free_path(global->path_head);

	// if (global->prev)
	// 	global = global->prev;
	// else if (global->next)
	// 	global = global->next;
	// else
	// 	global = NULL;
	return (*global_head);
}

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
	return (global);

}

static t_node	*pointer_2_free_node(t_node *list)
{
	// show_nodes(list);
	while (list)
	{
		// ft_putchar('x');
		if (*(list->passed) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}

int		follow_shortest_path(t_dijk *global, t_adjlist *alist)
{
	t_node	*node_list;
	t_node	*tmp_list;

	node_list = global->glist->head->next;
	if (!pointer_2_free_node(global->glist->head))
	{
		return (0);
	}
	while (node_list)
	{
		if (*(node_list->passed) == 0)
		{
			if ((tmp_list = pointer_2_free_node(node_list->next)))
				global = add_cpy_gpath(global);
			global->path_tail = add_node_2_path(node_list->id, global->path_tail);
			global->glist = pointer_2_glist(global->path_tail->id, alist->start);
			*(node_list->passed) = 1;
			global->nb_nodes++;
			if (tmp_list)
				global = global->next;
			node_list = tmp_list;
		}
		else
			node_list = node_list->next;
	}
	return (1);
}

t_dijk	*find_shortest_gpath(t_dijk *global_head)
{
	t_dijk	*shortest_gpath;

	if (!global_head)
		return(NULL);
	shortest_gpath = global_head;
	while (global_head)
	{
		if (global_head->nb_nodes < shortest_gpath->nb_nodes)
			shortest_gpath = global_head;
		global_head = global_head->next;
	}
	// ft_putnbr(shortest_gpath->nb_nodes);
	// ft_putchar('\n');
	return (shortest_gpath);
}