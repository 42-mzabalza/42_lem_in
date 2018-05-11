/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 18:13:05 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/10 18:13:08 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char		*find_free_node(t_node *node)
{
	while (node)
	{
		if (*(node->passed) == 0)
			return(node->id);
		node = node->next;
	}
	return (NULL);
}

t_path	*init_path(char *start)
{
	t_path 	*path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	path->id = start;
	path->total_cost = 0;
	path->next = NULL;
	path->prev = NULL;
	return (path);
}

t_path	*add_node_2_path(char *id, t_path *path)
{
	t_path *new_path;

	if (!(new_path = (t_path*)malloc(sizeof(t_path))))
		exit(-1);
	new_path->id = id;
	new_path->next = NULL;
	new_path->prev = path;
	path->next = new_path;
	path = new_path;
	new_path->total_cost = (new_path->prev->total_cost) + 1;
	return (path);
}

t_path	*rm_node_from_path(t_path *path)
{
	//si no queda mas por eliminar ?? segfault??
	path = path->prev;
	free(path->next);
	path->next = NULL;
	return (path);
}

t_path			*any_path(t_adjlist *alist)
{
	t_path 	*path;
	t_path	*final_path;
	t_glist *g_tmp;
	
	g_tmp = alist->start;
	path = init_path(g_tmp->head->id);
	final_path = path;
	if (!(g_tmp = pointer_2_glist(find_free_node(g_tmp->head), alist->start)))
	{
		ft_putstr("No path\n");
		exit(-1);
	}
	path = add_node_2_path(g_tmp->head->id, path);
	while (g_tmp->head->pos != 2)
	{
		*(g_tmp->head->passed) = 1;
		if (!(g_tmp = pointer_2_glist(find_free_node(g_tmp->head), alist->start)))
		{
			if (!path->prev)
			{
				ft_putendl("No path");
				exit(-1);
			}
			path = rm_node_from_path(path);
			g_tmp = pointer_2_glist(path->id, alist->start);
		}
		else
			path = add_node_2_path(g_tmp->head->id, path);
	}
	ft_putendl("reached end");
	return (final_path);
}