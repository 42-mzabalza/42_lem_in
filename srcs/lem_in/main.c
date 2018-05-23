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

static int	calc_nb_paths(void)
{
	return (2);
}

static	t_path		**realloc_allpaths(t_path **all_paths, int i)
{
	int 	j;
	t_path 	**tmp_path;

	tmp_path = all_paths;
	all_paths = (t_path **)malloc(sizeof(t_path *) * (i + 2));
	all_paths[i] = NULL;
	j = 0;
	while (tmp_path[j])
	{
		all_paths[j] = tmp_path[j];
		j++;
	}
	// free(tmp_path);
	return (all_paths);
}

static t_gpath  	*init_gpath(t_path *path, int i)
{
	t_gpath 	*g_paths;

	// g_paths = (t_gpath *)malloc(sizeof(t_gpath));
	if (!i)
		g_paths->prev = NULL;
	g_paths->next = NULL;
	g_paths->path_head = path;
	return(g_paths);
}

static t_adjlist	*init_alist()
{
	t_adjlist 	*alist;

	alist = (t_adjlist *)malloc(sizeof(t_adjlist));
	alist->st_end = 0;
	alist->nb_room = 0;
	alist->start = NULL;
	alist->end = NULL;
	return(alist);
}

int 				main()
{
	t_adjlist 	*adjlist;
	t_path		*path;
	t_path 		**all_paths;
	t_prev		*prev_list;
	int 		i;
	int			j;

	adjlist = init_alist();
	if (!get_data(adjlist))
	{
		free(adjlist);
		return (ft_str_error("ERROR\n", 1));
	}
	print_graph(adjlist);
	// if (!(prev_list = breath_first_search(adjlist->start)))
	// {
	// 	ft_putendl("No paths");
	// 	return (0);
	// }
	// path = create_path(prev_list);
	// all_paths = (t_path **)malloc(sizeof(t_path *) * 2);
	// all_paths[1] = NULL;
	// *all_paths = path;
	// i = 1;
	// while(1)
	// {
	// 	reset_map(adjlist->start, &all_paths[0]);
	// 	if (!(prev_list = breath_first_search(adjlist->start)))
	// 	{
	// 		j = 0;
	// 		ft_putendl("No paths");
	// 		while(all_paths[j])
	// 		{
	// 			show_path(all_paths[j]);
	// 			j++;
	// 		}
	// 		break ;
	// 	}
	// 	all_paths = realloc_allpaths(all_paths, i);
	// 	path = create_path(prev_list);
	// 	all_paths[i] = path;
	// 	i++;
	// }
	// return (0);
}
