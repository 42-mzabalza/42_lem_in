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
	// t_path		*path;
	// t_dijk		*global_paths;
	t_prev		*prev_list;

	adjlist = (t_adjlist *)malloc(sizeof(t_adjlist));
	if (!get_data(adjlist))
	{
		ft_putendl("ERROR");
		return (1);
		//meter ft_error() en libft YA
	}
	// print_graph(adjlist);
	// global_paths = dijkstra_path(adjlist);
	// show_global_paths(global_paths);
	// // path = any_path(adjlist);
	prev_list = breath_first_search(adjlist->start);
	// // show_path(path);

	// print_graph(adjlist);
	return (0);
}
