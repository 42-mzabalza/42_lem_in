/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 12:53:03 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 12:53:05 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main()
{
	t_adjlist 	adjlist;

	if (!get_data(&adjlist))
	{
		ft_putendl("ERROR");
		return (1);
	}
	//print_graph(adjlist);

	return (0);
}
