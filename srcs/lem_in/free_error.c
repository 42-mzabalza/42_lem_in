/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 16:45:00 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/16 16:45:18 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	free_alist_error(t_adjlist *alist, t_gpath 	*gpath, int out, char *str)
{
	if (!out)
	{
		ft_putendl(alist->info);
		ft_putchar('\n');
		show_answer(alist, gpath);
	}
	else
	{
		ft_putstr("ERROR");
		if (alist->flags & (1 << ('e' - 'a')))
		{
			if (!str)
			{
				ft_putstr(": line ");
				ft_putnbr(alist->info_i);
			}
			else
				ft_putstr(str);
		}
		ft_putchar('\n');
	}
	if (alist)
		free_adjlist(alist);
	if (gpath)
		free_map(gpath);
	return (out);
}

int 	free_error(char *line, t_node *node, int outInt)
{
	if (line)
		free(line);
	if (node)
		free_node(node);
	return(outInt);
}