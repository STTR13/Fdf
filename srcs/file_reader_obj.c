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

static char **initobjvertfill(char **temp)
{
	int nr;

	nr = 0;
	if (!(temp = ft_memalloc(sizeof(char **) * (3 * 15)))
		return (NULL);
	while (nr < 3)
	{
		if (!(temp[nr] = ft_strnew(15)))
			return (NULL);
		nr++;
	}
	return (temp);
}

vertex *objvertfill(vertex v, char *line, int i)
{
	int		j;
	int		x;
	int		nr;
	char	**temp;

	j = 0;
	x = 0;
	nr = 0;
	temp = initobjvertfill(temp);
	if (line[j] == 'v')
	{
		while (line[j] != '\0')
		{
			while (!(ft_isdigit(line[j]) || line[j] != '-')
				j++;
			while (ft_isdigit(line[j]) || line[j] == '-' ||line[j] == '.')
			{
				temp[nr][x] = line[j];
				j++;
				x++;
			}
			printf("%s\n", temp[nr]);
			if (line[j] == ' ')
				nr++;
		}
	}
	return (v);
}

vertex			*file_reader_obj(int fd)
{
	char	*line;
	char	*str;
	vertex	*lst;
	int		i;

	if (fd == -1)
		return (NULL);
	vertex = NULL;
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (!(vertex = objvertfill(lst, line, i)))
		free(line);
		i++;
	}
	close(fd);
	ft_strdel(&str);
	return (lst);
}
