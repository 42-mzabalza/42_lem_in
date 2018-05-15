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

int main()
{
	t_adjlist 	*adjlist;
	t_path		*path;
	// t_dijk		*global_paths;

	adjlist = (t_adjlist *)malloc(sizeof(t_adjlist));
	if (!get_data(adjlist))
	{
		ft_putendl("ERROR");
		return (1);
		//meter ft_error() en libft YA
	}
	print_graph(adjlist);
	
	//global_paths = dijkstra_path(adjlist);
	//show_global_paths(global_paths);
	path = any_path(adjlist);
	show_path(path);
	// while (i < nb_nodes)
	// {
	// 	adjlist[i] = (t_list *)malloc(sizeof(t_list));
	// 	adjlist[i]->head = NULL;
	// }
	// add_node(start, mid0, adjlist);
	// add_node(start, mid1, adjlist);
	// add_node(mid1, mid2, adjlist);
	// add_node(mid2, end, adjlist);
	return (0);
}
