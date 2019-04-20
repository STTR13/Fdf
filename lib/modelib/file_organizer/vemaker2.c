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

#include "modeling.h"

/*
** edgefiller will launch edgefiller_hor and edgefiller_ver.
** together, all of these functions will create links between
** certain vectors. edgefiller_hor will first create links in
** a horizontal line, followed by edgefiller_ver which will do
** the same for the vertical connections.
*/



/*static bool	edgefiller_hor(t_input *f, vertex **vt)
{
	edge *e;
	int	x;
	int	y;

	y = 0;
	while (y < f->lines)
	{
		x = 0;
		while (x < f->linelen)
		{
			if (x != f->linelen - 1)
				if (!(*e = add_edge(*e, vt[y * f->linelen + x], vt[y * f->linelen + x + 1])))
					return (0);
			if (y < f->lines - 1)
				if (!(*e = add_edge(*e, vt[y * f->linelen + x], vt[(y + 1) * f->linelen + x])))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}*/

static edge *edgefiller_quit(edge *e)
{
	free_edge(&e);
	return (NULL);
}

edge		*edgefiller(t_input *f, vertex **vt)
{
	edge *e;
	int	x;
	int	y;

	e = NULL;
	y = 0;
	while (y < f->lines)
	{
		x = 0;
		while (x < f->linelen)
		{
			if (x != f->linelen - 1)
				if (!(e = add_edge(e, vt[y * f->linelen + x], vt[y * f->linelen + x + 1])))
					return (edgefiller_quit(e));
			if (y < f->lines - 1)
				if (!(e = add_edge(e, vt[y * f->linelen + x], vt[(y + 1) * f->linelen + x])))
					return (edgefiller_quit(e));
			x++;
		}
		y++;
	}
	return (e);
}
