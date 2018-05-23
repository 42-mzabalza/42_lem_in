/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_answer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:56:52 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/20 19:56:54 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		show_ant(int ant_nb, t_path *path)
{

}

void		show_answer(t_path **all_paths, t_adjlist *alist, int nb_path)
{
	char **ans_matrix;
	int ant_nb;
	int nb_moves;
	t_path *path;
	int nb_ants;
	int i;
	int j;

	ans_matrix = (char **)malloc(sizeof(char *));
	nb_ants = alist->nb_ant;
	path = all_paths[0];
	ant_nb = 1;
	i = 1;
	j = 0;
	while(nb_ants)
	{
		path = all_paths[0];
		while (j < i && path)
		{
			show_ant(ant_nb + i, path);
			path = path->next;
			j++;
		}
		if (i < alist->nb_ant)
			i++;
		nb_ants--;
		path = path->next;
	}
}