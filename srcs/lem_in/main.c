/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:07:21 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 13:17:08 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

// CORRECTIONS
//---------------
// nombre nodo ya existe
// coordenadas ya existen
// duplicate pipe
// Error No paths, no mostrar el input map

t_node 			*init_node()
{
	t_node 	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		exit(1);
	node->id = NULL;
	node->pos = 0;
	node->passed = (int *)malloc(sizeof(int)); //es necesario?
	*(node->passed) = 0;
	node->occupied = (int *)malloc(sizeof(int)); //es necesario?
	*(node->occupied) = 0;
	return (node);
}

static t_gpath  	*init_gpath(t_path *path, int i)
{
	t_gpath 	*gpath;

	gpath = (t_gpath *)malloc(sizeof(t_gpath));
	if (!i)
		gpath->prev = NULL;
	gpath->next = NULL;
	gpath->path_head = path;
	gpath->nb_ants = 0;
	gpath->nb_nodes = path->ant;
	return(gpath);
}

static t_adjlist	*init_alist()
{
	t_adjlist 	*alist;

	alist = (t_adjlist *)malloc(sizeof(t_adjlist));
	alist->st_end = 0;
	alist->nb_room = 0;
	alist->start = NULL;
	alist->end = NULL;
	alist->info_i = 1;
	alist->info = NULL;
	return(alist);
}

int 				main(int ac, char **av)
{
	t_adjlist 	*adjlist;
	t_path		*path;
	t_gpath 	*gpath;
	t_prev		*prev_list;


	ft_putnbr(ft_options(ac, av));
	adjlist = init_alist();
	if (!get_data(adjlist))
		return (free_alist_error(adjlist, NULL, 1, NULL));
	if (!(prev_list = breath_first_search(adjlist->start)))
		return (free_alist_error(adjlist, NULL, 1, "Error: No paths founded"));
	path = create_path(prev_list);
	gpath = init_gpath(path, 0);
	while(1 && path->ant > 2)
	{
		reset_map(adjlist->start, gpath);
		if (!(prev_list = breath_first_search(adjlist->start)))
			break ;
		path = create_path(prev_list);
		add_2_gpath(gpath, path);
	}
	return (free_alist_error(adjlist, gpath, 0, NULL));
}
