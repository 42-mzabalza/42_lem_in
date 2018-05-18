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

static	t_path	**realloc_allpaths(t_path **all_paths, int i)
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

int main()
{
	t_adjlist 	*adjlist;
	t_path		*path;
	t_path 		**all_paths;
	t_prev		*prev_list;
	int 		i;
	int			j;

	adjlist = (t_adjlist *)malloc(sizeof(t_adjlist));
	if (!get_data(adjlist))
	{
		ft_putendl("ERROR");
		return (1);
		//meter ft_error() en libft YA
	}
	if (!(prev_list = breath_first_search(adjlist->start)))
	{
		ft_putendl("No paths");
		return (0);
	}
	path = create_path(prev_list);
	all_paths = (t_path **)malloc(sizeof(t_path *) * 2);
	all_paths[1] = NULL;
	*all_paths = path;
	i = 1;
	while(1)
	{
		reset_map(adjlist->start, &all_paths[0]);
		if (!(prev_list = breath_first_search(adjlist->start)))
		{
			j = 0;
			ft_putendl("No paths");
			while(all_paths[j])
			{
				show_path(all_paths[j]);
				j++;
			}
			return (0);
		}
		all_paths = realloc_allpaths(all_paths, i);
		path = create_path(prev_list);
		all_paths[i] = path;
		i++;
	}
	return (0);
}
