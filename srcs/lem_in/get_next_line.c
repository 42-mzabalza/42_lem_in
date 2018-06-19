/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabalza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:30:47 by mzabalza          #+#    #+#             */
/*   Updated: 2018/04/17 13:17:03 by mzabalza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_join(char *chaume, char *buff)
{
	char	*tmp;

	if (!chaume)
		chaume = ft_strdup(buff);
	else
	{
		tmp = chaume;
		chaume = ft_strjoin(chaume, buff);
		ft_strdel(&tmp);
	}
	return (chaume);
}

static char		*ft_fill_line(char *chaume, char **line)
{
	char	*tmp;
	int		len;

	len = 0;
	while (chaume[len] != '\n')
		len++;
	*line = ft_strsub(chaume, 0, len);
	tmp = chaume + (len + 1);
	tmp = ft_strdup(tmp);
	ft_strdel(&chaume);
	return (tmp);
}

static int		ft_nendl(char **chaume, int i, char **line)
{
	if (i == 0 && *chaume && **chaume && (!(ft_strchr(*chaume, '\n'))))
	{
		*line = ft_strdup(*chaume);
		ft_strdel(chaume);
		return (1);
	}
	return (0);
}

static int		ft_read(int fd, int *i, char **chaume, char **line)
{
	char		buff[BUFF_SIZE + 1];

	ft_memset(buff, 0, BUFF_SIZE + 1);
	while ((*i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(*chaume = ft_join(*chaume, buff)))
			return (-1);
		if ((ft_strchr(buff, '\n')))
		{
			if (!(*chaume = ft_fill_line(*chaume, line)))
				return (-1);
			return (1);
		}
		ft_memset(buff, 0, BUFF_SIZE + 1);
	}
	return (2);
}

int				get_next_line(const int fd, char **line)
{
	static char	*chaume = NULL;
	int			i;
	int			j;

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (chaume && ft_strchr(chaume, '\n'))
	{
		if (!(chaume = ft_fill_line(chaume, line)))
			return (-1);
		return (1);
	}
	j = ft_read(fd, &i, &chaume, line);
	if (!j)
		return (-1);
	else if (j == 1)
		return (1);
	if (i < 0)
		return (-1);
	if (ft_nendl(&chaume, i, line))
		return (1);
	return (0);
}
