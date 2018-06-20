/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:15:07 by mzabalza          #+#    #+#             */
/*   Updated: 2018/06/20 16:28:57 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numlen(int n)
{
	int len;

	len = 2;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n /= 10)
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*num;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = n;
	len = numlen(n);
	if (n < 0)
		n *= -1;
	if (!(num = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	num[--len] = '\0';
	while (len--)
	{
		num[len] = n % 10 + 48;
		n = n / 10;
	}
	if (sign < 0)
		num[0] = '-';
	return (num);
}
