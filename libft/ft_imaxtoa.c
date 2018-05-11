/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:15:07 by mzabalza          #+#    #+#             */
/*   Updated: 2018/01/16 22:08:54 by mzabalza         ###   ########.fr       */
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

char		*ft_itoa(intmax_t n)
{
	int		len;
	char	*num;
	int		i;
	int		temp;
	int		sign;

	if (n == -9223372036854775808)
		return (ft_strdup("-9223372036854775808"));
	sign = n;
	temp = n;
	len = numlen(n);
	if (n < 0)
		n *= -1;
	if (!(num = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	num[len - 1] = '\0';
	i = len - 2;
	while (len--)
	{
		num[i--] = (n % 10) + 48;
		n = n / 10;
	}
	if (sign < 0)
		num[0] = '-';
	return (num);
}
