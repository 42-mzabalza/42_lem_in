/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_graph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:17:13 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:06:55 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		print_list(t_glist *list)
{
	t_node *tmp;

	tmp = list->head;
	while (tmp)
	{
		if (tmp->pos == 1 || tmp->pos == 2)
			tmp->pos == 1 ? ft_putstr("\n##start\n") : ft_putstr("##end\n");
		ft_putstr(tmp->id);
		ft_putchar(' ');
		ft_putnbr(*(tmp->passed));
		if (tmp->next)
			ft_putstr(" -> ");
		tmp = tmp->next;
	}
}

void			print_graph(t_adjlist *adjlist)
{
	t_glist *tmp;

	ft_putendl("----map----");
	ft_putstr("number of ants: ");
	ft_putnbr(adjlist->nb_ant);
	ft_putstr("\nnumber of nodes: ");
	ft_putnbr(adjlist->nb_room);
	ft_putchar('\n');
	tmp = adjlist->start;
	while (tmp)
	{
		print_list(tmp);
		ft_putchar('\n');
		tmp = tmp->next;
	}
	ft_putendl("----finished map----");
}
