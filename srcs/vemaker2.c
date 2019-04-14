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



/*void	xlink(vertex *grid, t_input *file)
{
	vertex	*temp;

	if (0 < grid->v.x)
	{
		temp = grid - 1;
		grid->next[2] = temp;
	}
	if (grid->v.x == 0 || grid->v.x < file->linelen - 1)
	{
		temp = grid + 1;
		grid->next[0] = temp;
	}
}

void	ylink(vertex *grid, t_input *file)
{
	vertex	*temp;

	if (grid->v.y > 0)
	{
		temp = grid - file->linelen;
		grid->next[3] = temp;
	}
	if (grid->v.y == 0 || grid->v.y < file->lines - 1)
	{
		temp = grid + file->linelen;
		grid->next[1] = temp;
	}
}*/


edge	*edgefiller(t_input *f, vertex *v, int x, int y)
{
	edge *e;
	ve tv;

	e = NULL;
	while (y < f->lines)
	{
		x = 0;
		while (x < f->linelen - 1)
		{
			e = add_edge(e, find_vertex(v, createv(0, x, y, &tv)), \
			find_vertex(v, createv(0, x + 1, y, &tv)));
			x++;
		}
		y++;
	}
	x = 0;
	while (x < f->linelen)
	{
		y = 0;
		while (y < f->lines - 1)
		{
			e = add_edge(e, find_vertex(v, createv(0, x, y, &tv)), \
			find_vertex(v, createv(0, x , y + 1, &tv)));
			y++;
		}
		x++;
	}
	return (e);
}
