/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_hex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 15:42:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 15:42:48 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include "get_next_line.h"

typedef struct 		s_node
{
	char			*id;
	int				x;
	int				y;
	int				pos;
	struct s_node	*next;

}					t_node;

typedef struct 		s_glist
{
	t_node			*head;
	t_node			*tail;
	struct s_glist 	*next;
}					t_glist;

typedef struct 		s_adjlist
{
	int				nb_room;
	int				nb_ant;
	t_glist			*start;
	t_glist			*end;
}					t_adjlist;

int 				main();
int 				get_data(t_adjlist *adjlist);
void				add_node(t_node *node, t_adjlist *alist);
t_adjlist			*init_adjlist();
void				print_graph(t_adjlist *adjlist);

#endif
