/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:00:20 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/11 17:19:21 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		new_line(char **str, char **line, int fd, int ret)
{
	char	*temp;
	int		len;

	len = 0;
	while (str[fd][len] != '\n' && str[fd][len] != '\0')
		len++;
	if (str[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(str[fd], 0, len)) || \
			!(temp = ft_strdup(str[fd] + len + 1)))
			return (ft_strdel_neg(&temp));
		ft_strdel(&str[fd]);
		str[fd] = temp;
		if (str[fd][0] == '\0')
			ft_strdel(&str[fd]);
	}
	else if (str[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		if (!(*line = ft_strdup(str[fd])))
			return (ft_strdel_neg(&str[fd]));
		ft_strdel(&str[fd]);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*str[OPEN_MAX];
	char		buf[BUFF_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL || fd > OPEN_MAX)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (str[fd] == NULL)
			if (!(str[fd] = ft_strnew(1)))
				return (-1);
		temp = str[fd];
		if (!(str[fd] = ft_strjoin(temp, buf)))
			return (ft_strdel_neg(&str[fd]));
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (str[fd] == NULL || str[fd][0] == '\0'))
		return (0);
	return (new_line(str, line, fd, ret));
}
