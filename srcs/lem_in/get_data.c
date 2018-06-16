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

static int 	get_room(t_node *node, char *line)
{
	char **rm;
	int i;
	int flag;

	flag = 0;
	if (ft_nb_words(line, ' ') != 3)
		return (0);
	if ((rm = ft_strsplit(line, ' ')) && is_integer(rm[1]) && is_integer(rm[2]))
	{
		node->id = ft_strdup(rm[0]);
		node->x = ft_atoi(rm[1]);
		node->y = ft_atoi(rm[2]);
		flag = 1;
	}
	i = 0;
	while (rm[i])
	{
		free(rm[i]);
		i++;
	}
	free(rm);
	if (!flag)
		return (0);
	return (1);
}

static int	get_node(char **line, t_adjlist *adjlist)
{
	t_node 	*node;
	int 	flag;

	node = init_node();
	if (!check_start_end(line, &flag, adjlist, node))
		return(free_error(*line, node, 0)); //liberar node y line
	if ((*line[0]) == '#' && !flag)
		return (free_error(NULL, node, 1));
	else
		skip_comment(line);
	if (*line && line_type(*line, ' ') == 2)
	{
		if (!get_room(node, *line))
			return(free_error(*line, node, 0));
	}
	else
		return(free_error(*line, node, 0));
	add_glist(node, adjlist);
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
		if (!get_node(&line, adjlist))
			return (0);
		new_info_line(adjlist, line);
	}
	if (adjlist->st_end != 5)
		return(free_error(line, NULL, 0));
	if (!j || !add_connection(line, adjlist))
		return(free_error(line, NULL, 0));
	new_info_line(adjlist, line);
	while (get_next_line(0, &line) > 0)
	{
		if (!add_connection(line, adjlist))
			return(free_error(line, NULL, 0));
		new_info_line(adjlist, line);
	}
	return (1);
}
