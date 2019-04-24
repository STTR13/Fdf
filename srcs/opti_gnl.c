/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 14:58:40 by staeter           #+#    #+#             */
/*   Updated: 2019/04/20 14:58:41 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_next_line_opti(int fd, char **line)
{
	static char *ptr[2];
	int			r;

	if (fd == -7919)
	{
		free(ptr[0]);
		ptr[0] = NULL;
		return (2);
	}
	if (!ptr[0])
		if (!(ptr[0] = reader(fd))\
		|| !(ptr[1] = ptr[0]))
			return (-1);
	*line = ptr[1];
	while (*ptr[1] != '\n' && *ptr[1] != '\0')
		ptr[1]++;
	r = (*(ptr[1]) == '\n') ? 1 : 0;
	*ptr[1] = '\0';
	ptr[1]++;
	return (r);
}
