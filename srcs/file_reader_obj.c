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

static int linelen(char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			j++;
			while ((ft_isdigit(line[i]) || line[i] == '/') && line[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (j);
}

static bool		edgefiller_obj(warehouse *wh, int *x, char *line, int j)
{
	int i;

	i = -1;
	while (++i < j - 1)
	{
		if (!(wh->e = add_edge(wh->e, find_vertex_pos(wh->v, x[i]),\
		find_vertex_pos(wh->v, x[i + 1]))))
			return (0);
	}
	if (i > 1)
		if (!(wh->e = add_edge(wh->e, find_vertex_pos(wh->v, x[0]),\
		find_vertex_pos(wh->v, x[i]))))
			return (0);
	return (1);
}

static bool		edgeput_obj(warehouse *wh, char *line, int i)
{
	int	*x;
	int	j;

	j = linelen(line);
	if (!(x = ft_memalloc(sizeof(int *) * j)))
		return (0);
	j = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			x[j] = ft_atoi(&line[i]);
			j++;
			while ((ft_isdigit(line[i]) || line[i] == '/') && line[i] != '\0')
			i++;
		}
		i++;
	}
	if (!(edgefiller_obj(wh, x, line, j)))
		return (0);
	ft_memdell(x);
	return (1);
}

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
		v = add_vertex(v, set_ve(ft_atof(&line[z]), ft_atof(&line[x]), \
		ft_atof(&line[y]), &ret), i);
	return (v);
}

bool			file_reader_obj(int fd, warehouse *wh)
{
	char	*line;
	int		i;

	if (fd == -1)
		return (0);
	i = 1;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'v' && line[1] == ' ')
		{
			if (!(wh->v = objvertfill(wh->v, line, i)))
				return (0);
			i++;
		}
		else if (line[0] == 'f' && line[1] == ' ')
		{
			if (!(edgeput_obj(wh, line, 0)))
				return (0);
		}
		free(line);
	}
	close(fd);
	return (1);
}
