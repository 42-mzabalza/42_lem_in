/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:00:50 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/18 21:30:16 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*create_path(t_prev *reverse_path)
{
	t_prev *tail;
	t_path *path;

	tail = reverse_path;
	if (!reverse_path)
		return (NULL);
	path = (t_path *)malloc(sizeof(t_path));
	path->id = reverse_path->current;
	path->prev = NULL;
	path->next = NULL;
	path->ant = 1;
	reverse_path = find_previous(reverse_path->previous, tail);
	while (reverse_path)
	{
		path->prev = (t_path *)malloc(sizeof(t_path));
		path->prev->next = path;
		path->prev->prev = NULL;
		path = path->prev;
		path->ant = (path->next->ant) + 1;
		path->id = reverse_path->current;
		reverse_path = find_previous(reverse_path->previous, tail);
	}
	free_prev_list(tail);
	return (path);
}
