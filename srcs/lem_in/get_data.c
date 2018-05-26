/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 13:16:40 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 13:16:53 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node 			*init_node()
{
	t_node 	*node;

	if (!(node = (t_node *)malloc(sizeof(t_node))))
		exit(1);
	node->pos = 0;
	node->passed = (int *)malloc(sizeof(int)); //es necesario?
	*(node->passed) = 0;
	node->occupied = (int *)malloc(sizeof(int)); //es necesario?
	*(node->occupied) = 0;

	return (node);
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
	if (ft_nb_words(line, ' ') != 3)
		return (0);
	if ((rm = ft_strsplit(line, ' ')) && is_integer(rm[1]) && is_integer(rm[2]))
	{
		node->id = ft_strdup(rm[0]);
		node->x = ft_atoi(rm[1]);
		node->y = ft_atoi(rm[2]);
	}
	else
		return (0);
	i = 0;
	while (rm[i])
	{
		free(rm[i]);
		i++;
	}
	free(rm);
	return (1);
}

static int	get_node(char *line, t_adjlist *adjlist)
{
	t_node 	*node;
	int flag;

	// ft_putendl(line);
	flag = 0;
	node = init_node();
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
	{
		flag = 1;
		node->pos = 2;
		adjlist->st_end++;
		if (!ft_strcmp(line, "##start"))
		{
			*(node->passed) = 1;
			node->pos = 1;
		}
		free(line);
		get_next_line(0, &line); // problema si no tiene if > 0??
	}
	// if (line[0] == '#' && line[1] != '#' && !flag)
	if (line[0] == '#' && !flag)
	
		return (1);
	else
		skip_comment(&line);
	if (line && line_type(line, ' ') == 2)
	{
		if (!get_room(node, line))
			return (0);
	}
	else
	{
		free(line);
		ft_putstr("falta node despues de ##");
		return (0);
	}
	add_glist(node, adjlist);
	return (1);
}

int 			get_data(t_adjlist *adjlist)
{
	char	*line;
	int 	i;
	int     j;

	if (!(adjlist->nb_ant = get_nb_ants()))
		return (ft_str_error("Ant input error\n", 0));
	while ((j = get_next_line(0, &line)) > 0 && (line_type(line, '-') == 0))
	{
		if (!get_node(line, adjlist))
			return (0);
		free(line);
	}
	if (adjlist->st_end != 2)
		return (ft_str_error("No start end problem\n", 0));
	if (!j)
		return (ft_str_error("No links\n", 0));
	if (!add_connection(line, adjlist)) //si el archivo esta vacio???
			return (0); // room no existe ?que hago??
	i = 0;
	while (get_next_line(0, &line) > 0) //line_type
	{
		add_connection(line, adjlist);
		free(line);
	}
	return (1);
}
