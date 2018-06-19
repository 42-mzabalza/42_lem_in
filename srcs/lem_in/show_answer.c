/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:56:52 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:37:38 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		reset_gpaths(t_gpath *gpath)
{
	t_path *path_tmp;

	while (gpath)
	{
		path_tmp = gpath->path_head;
		while (path_tmp)
		{
			path_tmp->ant = 0;
			path_tmp = path_tmp->next;
		}
		gpath = gpath->next;
	}
}

static int		sum_nodes(int nb_paths, t_gpath *gpath)
{
	int sum;

	sum = 0;
	while (nb_paths)
	{
		sum += gpath->nb_nodes - 2;
		nb_paths--;
		gpath = gpath->next;
	}
	return (sum);
}

static void		distribute_ants(int nb_paths, int nb_ant, t_gpath *gpath_head)
{
	int remainder;
	int ant_div;
	int nb_moves;

	nb_moves = sum_nodes(nb_paths, gpath_head) + nb_ant;
	ant_div = nb_moves / nb_paths;
	remainder = nb_moves % nb_paths;
	while (nb_paths--)
	{
		gpath_head->nb_ants = ant_div - (gpath_head->nb_nodes - 2);
		if (remainder)
		{
			gpath_head->nb_ants++;
			remainder--;
		}
		gpath_head = gpath_head->next;
	}
}

static int		nb_path_needed(t_adjlist *alist, t_gpath *gpath)
{
	int		i;
	int		moves;
	int		rem;
	t_gpath	*gpath_head;

	gpath_head = gpath;
	gpath->nb_ants = alist->nb_ant;
	moves = gpath->nb_ants + (gpath->nb_nodes - 2);
	gpath = gpath->next;
	i = 1;
	while (gpath && moves > (gpath->nb_nodes - 1))
	{
		i++;
		rem = (moves + (gpath->nb_nodes - 2)) % i;
		rem = (sum_nodes(i, gpath_head) + alist->nb_ant) % i;
		moves = (sum_nodes(i, gpath_head) + alist->nb_ant) / i;
		if (rem)
			moves++;
		distribute_ants(i, alist->nb_ant, gpath_head);
		gpath = gpath->next;
	}
	return (moves);
}

void			show_answer(t_adjlist *alist, t_gpath *gpath)
{
	t_gpath	*gpath_head;
	int		moves;

	gpath_head = gpath;
	moves = nb_path_needed(alist, gpath);
	reset_gpaths(gpath_head);
	solution_format(gpath_head, moves, alist->nb_ant);
}
