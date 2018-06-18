/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <mzabalza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:16:40 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/12 13:49:17 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	check_start_end(char **line, int *flag, t_adjlist *adjlist, t_node *node)
{
	*flag = 0;
	if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end"))
	{
		*flag = 1;
		node->pos = 2;
		(adjlist->st_end) += 2;
		if (!ft_strcmp(*line, "##start"))
		{
			*(node->passed) = 1;
			node->pos = 1;
			(adjlist->st_end)++;
		}
		new_info_line(adjlist, *line);
		if (!(get_next_line(0, &(*line)) > 0))
			return (0);
	}
	return (1);
}


int		line_type(char *line, char c)
{
	int count;

	count = 0;
	if (line[0] == 'L')
	 	return (0);
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

static int 	get_room(t_node *node, char *line, t_adjlist *alist)
{
	char **rm;
	int flag;

	flag = 0;
	rm = NULL;
	if (ft_nb_words(line, ' ') != 3)
		return (0);
	if ((rm = ft_strsplit(line, ' ')) && is_integer(rm[1]) && is_integer(rm[2]))
	{
		if (!(node->id = ft_strdup(rm[0])))
			return (0);
		node->x = ft_atoi(rm[1]);
		node->y = ft_atoi(rm[2]);
		flag = 1;
	}
	free_tab(rm);
	if (pointer_2_glist(node->id, alist->start))
		return (0);
	if (!flag)
		return (0);
	return (1);
}

static int	get_node(char **line, t_adjlist *adjlist)
{
	t_node 	*node;
	int 	flag;

	if (!(node = init_node(1)))
		return(free_error(*line, NULL, 0));
	if (!check_start_end(line, &flag, adjlist, node))
		return(free_error(*line, node, 0));
	if ((*line[0]) == '#' && !flag)
		return (free_error(NULL, node, 1));
	else
		skip_comment(adjlist, line);
	if (*line && line_type(*line, ' ') == 2)
	{
		if (!get_room(node, *line, adjlist))
			return(free_error(*line, node, 0));
	}
	else
		return(free_error(*line, node, 0));
	if (!add_glist(node, adjlist))
		return(free_error(*line, node, 0));
	return (1);
}

int 			get_data(t_adjlist *adjlist)
{
	char	*line;
	int     j;

	if (!(adjlist->nb_ant = get_nb_ants(adjlist)))
		return (0);
	while ((j = get_next_line(0, &line)) > 0 && (line_type(line, '-') == 0))
	{
		if (!get_node(&line, adjlist) || !new_info_line(adjlist, line))
			return (0);
	}
	if (adjlist->st_end != 5)
		return(free_error(line, NULL, 0));
	if (!j || !add_connection(line, adjlist))
		return(free_error(line, NULL, 0));
	if (!new_info_line(adjlist, line))
		return (0);
	while (get_next_line(0, &line) > 0)
	{
		if (!add_connection(line, adjlist))
			return(free_error(line, NULL, 0));
		if (!new_info_line(adjlist, line))
			return (0);
	}
	return (1);
}
