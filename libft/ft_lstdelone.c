/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 19:04:39 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:38:11 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *alstcpy;

	alstcpy = *alst;
	*alst = alstcpy->next;
	del(alstcpy->content, alstcpy->content_size);
	free(alstcpy);
	*alst = NULL;
}
