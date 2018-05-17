/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:32:19 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/17 14:35:12 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_glist		*find_start(t_glist *glist)
{
	while (glist)
	{
		if (glist->head->pos == 1)
			return (glist);
		glist = glist->next;
	}
	return (NULL);
}
