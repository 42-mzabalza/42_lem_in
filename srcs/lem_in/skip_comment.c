/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 17:05:30 by mzabalza          #+#    #+#             */
/*   Updated: 2018/05/23 17:05:32 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		skip_comment(t_adjlist *alist, char **line)
{
	while ((*line)[0] == '#')
	{
		if (!new_info_line(alist, *line))
			return (0);
		get_next_line(0, &(*line));
	}
	return (1);
}
