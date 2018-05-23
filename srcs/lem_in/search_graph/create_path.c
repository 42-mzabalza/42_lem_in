/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 15:00:50 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/18 15:17:15 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path		*create_path(t_prev *reverse_path)
{
	t_prev *tail;
	t_path *path;
	// t_path *path_head;

	tail = reverse_path;
	if (!reverse_path)
		return (NULL);
	path = (t_path *)malloc(sizeof(t_path));
	path->id = reverse_path->current;
	path->prev = NULL;
	path->next = NULL;
	// path_head = path;
	reverse_path = find_previous(reverse_path->previous, tail);
	while(reverse_path)
	{
		path->prev = (t_path *)malloc(sizeof(t_path));
		path->prev->next = path;
		path->prev->prev = NULL;
		path = path->prev;
		path->id = reverse_path->current;
		reverse_path = find_previous(reverse_path->previous, tail);
	}
	return (path);
}
