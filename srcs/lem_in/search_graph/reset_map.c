/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 14:56:38 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/18 15:00:41 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int 		is_in_path(char *id_room, t_gpath *gpath)
{
	t_path *tmp;

	while(gpath)
	{
		tmp = gpath->path_head;
		while (tmp)
		{
			if (!ft_strcmp(tmp->id, id_room)) //mirar mi ft_strcmp!!!!
				return (1);
			tmp = tmp->next;
		}
		gpath = gpath->next;
	}
	return (0);
}

void			reset_map(t_glist *glist_start, t_gpath *gpath)
{
	while (glist_start)
	{
		if (!is_in_path(glist_start->head->id, gpath))
			*(glist_start->head->passed) = 0;
		if (glist_start->head->pos == 2)
			*(glist_start->head->passed) = 0;
		glist_start = glist_start->next;
	}
}	
