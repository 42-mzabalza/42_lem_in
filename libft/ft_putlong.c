/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 22:42:19 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/25 18:01:45 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong(long int n)
{
	if (n > 9223372036854775807 || n < MINLONG)
		return ;
	if (n == MINLONG)
	{
		ft_putstr("−9223372036854775807");
		return ;
	}
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 10)
	{
		ft_putlong(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
