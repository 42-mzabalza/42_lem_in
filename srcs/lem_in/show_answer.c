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

static int	nb_path_needed(t_adjlist *alist, t_gpath *gpath)
{
	int i;
	int moves;

	gpath->nb_ants = alist->nb_ant;
	moves = gpath->nb_ants + (gpath->nb_nodes - 2);
	i = 1;
	gpath = gpath->next;
	while(gpath && moves > (gpath->nb_nodes - 1))
	{
		i++;
		moves = (moves + (gpath->nb_nodes - 1)) / 2;
		gpath = gpath->next;
	}
	return (moves);
}

void		show_answer(t_adjlist *alist, t_gpath *gpath)
{
	ft_putstr("number of moves: ");
	ft_putnbr(nb_path_needed(alist, gpath));
	ft_putchar('\n');
}