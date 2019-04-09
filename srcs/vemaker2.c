/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:17:08 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/15 12:17:10 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	edgefiller_hor(t_input *f, vertex *v, edge **e)
{
	int x;
	int y;

	y = 0;
	while (y < f->lines)
	{
		x = 0;
		while (x < f->linelen - 1)
		{
			*e = add_edge(*e, find_vertex(v, createv(0, x, y)), \
			find_vertex(v, createv(0, x + 1, y)));
			x++;
		}
		y++;
	}
}

static void	edgefiller_ver(t_input *f, vertex *v, edge **e)
{
	int x;
	int y;

	x = 0;
	while (x < f->linelen)
	{
		y = 0;
		while (y < f->lines - 1)
		{
			*e = add_edge(*e, find_vertex(v, createv(0, x, y)), \
			find_vertex(v, createv(0, x , y + 1)));
			y++;
		}
		x++;
	}
}

edge	*edgefiller(t_input *f, vertex *v)
{
	edge *e;

	e = NULL;
	edgefiller_hor(f, v, &e);
	edgefiller_ver(f, v, &e);
	return (e);
}
