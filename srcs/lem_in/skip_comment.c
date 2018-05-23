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

void	skip_comment(char *line)
{
	// while (line[0] == '#' && line[1] != '#')
	while (line[0] == '#')
	{
		ft_putendl(line);
		free(line);
		ft_putchar('x');
		get_next_line(0, &line);
		ft_putendl(line);
	}
	ft_putendl(line);
}
