

#include "libft.h"

/*
**RETURN  0 no number
**RETURN  1 positive number
**RETURN -1	negative number
*/

int		ft_isnum(char *str)
{
	int i;
	int neg;

	neg = 0;
	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while(str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (neg)
		return (-1);
	return (1);
}
