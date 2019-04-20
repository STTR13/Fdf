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
#include <stdio.h> //(t)

int		get_next_line_opti(int fd, char **line)
{
	static char *ptr[2];
	int			r;

	//printf("gnl_opti\n");
	if (fd == -7919)
	{
		//printf("free gnl_opti\n");
		free(ptr[0]);
		ptr[0] = NULL;
		return (2);
	}
	if (!ptr[0])
	{
		//printf("ptr NULL\n");
	 	if (!(ptr[0] = reader(fd)) || !(ptr[1] = ptr[0]))
		{
			//printf("reader fail\n");
			return (-1);
		}
	}
	//printf("%p\n\"%s\"\n", ptr[0], ptr[0]);
	*line = ptr[1];
	while (*ptr[1] != '\n' && *ptr[1] != '\0')
	{
		//printf("%p: '%c'\n", ptr[1], *ptr[1]);
		ptr[1]++;
	}
	//printf("%s\n", *line);
	r = (ptr[1] == '\0') ? 0 : 1;
	*ptr[1] = '\0';
	ptr[1]++;
	return (r);
}
