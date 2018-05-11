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

t_path *dijkstra_path(t_adjlist *alist)
{
	t_path *path;
	t_path *final_path;
	t_glist *g_tmp;

	g_tmp = alist->start;
	path = init_path(g_tmp->head->id);
	final_path = path;
	if (!(g_tmp = pointer_2_glist(find_free_node(g_tmp->head), alist->start)))
	{
		ft_putstr("No path\n");
		exit(-1);
	}
	return (final_path);
}
