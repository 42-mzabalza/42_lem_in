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
// duplicate pipe

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
	alist->info_i = 0;
	// alist->info = (char *)malloc(sizeof(char));
	alist->info = NULL;
	return(alist);
}

int 				main()
{
	t_adjlist 	*adjlist;
	t_path		*path;
	t_gpath 	*gpath;
	t_prev		*prev_list;

	adjlist = init_alist();
	if (!get_data(adjlist))
	{
		free_adjlist(adjlist);
		return (ft_str_error("ERROR\n", 1));
	}
	ft_putendl(adjlist->info);
	print_graph(adjlist);
	ft_putchar('\n');
	if (!(prev_list = breath_first_search(adjlist->start)))
	{
		ft_putendl("No paths");
		return (0);
	}
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
	show_answer(adjlist, gpath);
	free_adjlist(adjlist);
	free_map(gpath);

	// ft_putchar('\n');

	return (0);
}
