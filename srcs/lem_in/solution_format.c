/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:08:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/27 16:08:05 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

// static void	show_ant_move2(t_gpath *gpath)
// {
// 	t_path *path_tmp;

// 	while(gpath)
// 	{
// 		path_tmp = gpath->path_head->next;
// 		while(path_tmp) //while(path_tmp->ant)
// 		{
// 			if(path_tmp->ant)
// 			{
// 				ft_putchar('L');
// 				ft_putnbr(path_tmp->ant);
// 				ft_putchar('-');
// 				ft_putstr(path_tmp->id);
// 				ft_putchar(' ');
// 			}
// 			else
// 				break;
// 			path_tmp = path_tmp->next;
// 		}
// 		gpath = gpath->next;
// 	}
// }

static int	run_ants(int nb_ants, t_path *path)
{
	int i;


	i = 1;
	// show_path(path);
	while(path && !(path->ant))
	{
		// ft_putnbr(i++);
		path = path->next;
	}
	// ft_putchar('i');
	if (!path || !path->next)
	{
		if (nb_ants)
			return (1);
		return (0);
	}
	// ft_putchar('k');
	while(path)
	{
		if (!(path->next->next) || path->next->ant == 0)
			break;
		path = path->next;
	}
	// ft_putchar('e');
	while(path->ant)
	{
		path->next->ant = path->ant;
		path->ant = 0;
		path = path->prev;
	}
	return (1);
}

static void	show_ant_move(t_gpath *gpath)
{
	t_path *path_tmp;

	path_tmp = gpath->path_head->next;
	while(path_tmp) //while(path_tmp->ant)
	{
		if(path_tmp->ant)
		{
			ft_putchar('L');
			ft_putnbr(path_tmp->ant);
			ft_putchar('-');
			ft_putstr(path_tmp->id);
			ft_putchar(' ');
		}
		// else
		// 	break;
		path_tmp = path_tmp->next;
	}
}

void 		solution_format(t_gpath *gpath, int moves, int nb_ants)
{
	t_gpath *gpath_head;
	int i;
	int j;

	i = 1;
	j = 1;
	gpath_head = gpath;
	while(j <= moves)
	{
		ft_putnbr(j);
		ft_putchar(' ');
		gpath = gpath_head;
		while(gpath)
		{
			run_ants(gpath->nb_ants, gpath->path_head->next);
			if (gpath->nb_ants)
			{
				// ft_putnbr(gpath->nb_ants);
				// ft_putchar(' ');
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
	// show_gpaths(gpath_head);
	
}