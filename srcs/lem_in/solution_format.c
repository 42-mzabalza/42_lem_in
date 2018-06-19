/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:08:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:42:17 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		run_ants(int nb_ants, t_path *path)
{
	int i;

	i = 1;
	while (path && !(path->ant))
		path = path->next;
	if (!path || !path->next)
	{
		if (nb_ants)
			return (1);
		return (0);
	}
	while (path)
	{
		if (!(path->next->next) || path->next->ant == 0)
			break ;
		path = path->next;
	}
	while (path->ant)
	{
		path->next->ant = path->ant;
		path->ant = 0;
		path = path->prev;
	}
	return (1);
}

static void		show_ant_move(t_gpath *gpath)
{
	t_path *path_tmp;

	path_tmp = gpath->path_head->next;
	while (path_tmp->next)
		path_tmp = path_tmp->next;
	while (path_tmp)
	{
		if (path_tmp->ant)
		{
			ft_putchar('L');
			ft_putnbr(path_tmp->ant);
			ft_putchar('-');
			ft_putstr(path_tmp->id);
			ft_putchar(' ');
		}
		path_tmp = path_tmp->prev;
	}
}

void			solution_format(t_gpath *gpath, int moves, int nb_ants)
{
	t_gpath	*gpath_head;
	int		i;
	int		j;

	i = 1;
	j = 1;
	gpath_head = gpath;
	while (j <= moves)
	{
		gpath = gpath_head;
		while (gpath)
		{
			run_ants(gpath->nb_ants, gpath->path_head->next);
			if (gpath->nb_ants)
			{
				gpath->path_head->next->ant = i;
				gpath->nb_ants--;
				i++;
			}
			show_ant_move(gpath);
			gpath = gpath->next;
		}
		j++;
		ft_putchar('\n');
	}
}
