/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:57:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/24 10:01:32 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
/*
** These functions will read the file that has been sent with the
** executable. The information will be stored in all of the
** necessary structures.
*/

static int		linelen(char *line)
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

static t_bool	edgeput_obj(t_warehouse *wh, char *line, int i)
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
			x[j] = ft_atoi(&line[i]) - 1;
			j++;
			while ((ft_isdigit(line[i]) || line[i] == '/') && line[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (!(wh->e = edgefiller_obj(wh, x, j)))
		return (0);
	ft_memdell(x);
	return (1);
}

static t_vertex	*objvertfill(t_vertex *v, char *line, int i)
{
	int		y;
	int		x;
	int		z;
	t_ve	ret;

	x = -1;
	while (line[++x] != '\0')
		if (line[x] == '-' || ft_isdigit(line[x]))
			break ;
	y = x + 1;
	while (line[y] != ' ')
		y++;
	z = y + 1;
	while (line[z] != ' ')
		z++;
	if (!(v = add_vertex(v, set_ve(ft_atof(&line[z]), ft_atof(&line[x]), \
	ft_atof(&line[y]), &ret), i)))
		return (NULL);
	return (v);
}

static t_bool	code_selector(t_warehouse *wh, char *line, int *i)
{
	if (ft_strncmp(line, "v ", 2) == 0)
	{
		if (!(wh->v = objvertfill(wh->v, line, *i)))
			return (0);
		*i += 1;
	}
	else if (ft_strncmp(line, "f ", 2) == 0)
	{
		if (*i != 0)
		{
			wh->tab = new_vertex_tab(wh->v, *i);
			*i = 0;
		}
		if (!(edgeput_obj(wh, line, 0)))
			return (0);
	}
	return (1);
}

t_bool			file_reader_obj(int fd, t_warehouse *wh)
{
	char	*line;
	int		i;

	if (fd == -1)
		return (0);
	i = 0;
	while (get_next_line_opti(fd, &line) == 1)
		if (!(code_selector(wh, line, &i)))
			return (0);
	close(fd);
	get_next_line_opti(-7919, &line);
	if (!(wh->e))
		return (0);
	return (1);
}
