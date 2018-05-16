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

static void 	get_room(t_node *node, char *line)
{
	//ALGUNA PROTECCION MAS DEL INPUT: Si hay 2 espacios pero que haya tres palabras.
	//ft_nwords?
	char **rm;
	int i;

	if ((rm = ft_strsplit(line, ' ')) && ft_isnum(rm[1]) && ft_isnum(rm[2]))
	{
		node->id = ft_strdup(rm[0]);
		node->x = ft_atoi(rm[1]);
		node->y = ft_atoi(rm[2]);
	}
	else
		exit(1);
	i = 0;
	while (rm[i])
	{
		free(rm[i]);
		i++;
	}
	free(rm);
}

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
	// if (line[0] == '#' || line[0] == 'L') // L???
	// 	return (0);
	while (*line)
	{
		if (*line == c)
			count++;
		line++;
	}
	return (count);
}

static void	get_node(char *line, t_adjlist *adjlist)
{
	t_node 	*node;

	node = init_node();
	if (!ft_strcmp(line, "##start") || !ft_strcmp(line, "##end"))
	{
		node->pos = 2;
		if (!ft_strcmp(line, "##start"))
		{
			*(node->passed) = 1;
			node->pos = 1;
		}
		free(line);
		get_next_line(0, &line);
	}
	if (line && line_type(line, '#') == 1 && line[0] == '#')//que haya linea
	{
		free(line);
		get_next_line(0, &line);
	}
	if (line && line_type(line, ' ') == 2)
		get_room(node, line);
	else
	{
		ft_putstr("' ' != 2");
		exit(1);
	}
	add_glist(node, adjlist);
}

int 			get_data(t_adjlist *adjlist)
{
	char	*line;
	int 	i;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_isnum(line) != 1) //incluye 0??
		{
			ft_putstr("No ants\n");
			exit(1);
		}
		adjlist->nb_ant = ft_atoi(line);
		free(line);
	}
	ft_putnbr(adjlist->nb_ant);
	while (get_next_line(0, &line) > 0 && (line_type(line, '-') == 0))
	{
		get_node(line, adjlist);
		free(line);
	}
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
