/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:28:43 by mzabalza          #+#    #+#             */
/*   Updated: 2017/11/17 00:42:18 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *tmp;
	t_list *tmp2;

	if (lst == NULL)
		return (NULL);
	tmp = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	tmp2 = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (tmp2);
}
