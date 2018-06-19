/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <mzabalza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 19:10:41 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 20:46:42 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_map(t_gpath *gpath)
{
	t_path	*tmp_path;
	t_gpath	*tmp_gpath;

	while (gpath)
	{
		tmp_gpath = gpath;
		while (gpath->path_head)
		{
			tmp_path = gpath->path_head;
			gpath->path_head = gpath->path_head->next;
			free(tmp_path);
		}
		gpath = gpath->next;
		free(tmp_gpath);
	}
}

void	free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_node(t_node *node)
{
	free(node->occupied);
	free(node->passed);
	free(node->id);
	free(node);
}

void	free_glist(t_glist *glist)
{
	t_node *tmp;

	tmp = glist->head;
	glist->head = glist->head->next;
	free_node(tmp);
	while (glist->head)
	{
		tmp = glist->head;
		glist->head = glist->head->next;
		free(tmp->id);
		free(tmp);
	}
	free(glist);
}
