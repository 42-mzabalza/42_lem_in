/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_info_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:58:11 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/12 15:58:14 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

char 	*new_info_line(char *info, char *line)
{
	char *tmp;

	tmp = info;
	info = ft_strjoin(info, "\n");
	free(tmp);
	tmp = info;
	info = ft_strjoin(info, line);
	free(tmp);
	return (info);
}

