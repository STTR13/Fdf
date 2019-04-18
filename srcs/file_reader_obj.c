/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:57:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:48:07 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static vertex	*objvertfill(vertex *v, char *line, int i)
{
	int		y;
	int		x;
	int		z;
	ve		ret;

	x = -1;

		while (line[++x] != '\0')
			if (line[x] == '-' || ft_isdigit(line[x]))
				break;
		y = x + 1;
		while (line[y] != ' ')
			y++;
		z = y + 1;
		while (line[z] != ' ')
			z++;
		v = add_vertex(v, createv(ft_atof(&line[z]), ft_atof(&line[x]), \
		ft_atof(&line[y]), &ret), i);
	return (v);
}

vertex			*file_reader_obj(int fd)
{
	char	*line;
	vertex	*lst;
	int		i;

	if (fd == -1)
		return (NULL);
	lst = NULL;
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v')
		{
			if (!(lst = objvertfill(lst, line, i)))
				return (NULL);
		}
		free(line);
		i++;
	}
	close(fd);
	return (lst);
}
