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
** edgefiller will create links between certain vectors.
** first it will create links in a horizontal fashion and then
** vertically.
** edgefiller_obj will create links for .obj files, using the
** lines beginning with "f " followed by the information in the file
*/

static t_edge	*edgefiller_quit(t_edge *e)
{
	free_edge(&e);
	return (NULL);
}

t_edge			*edgefiller_obj(t_warehouse *wh, int *x, int j)
{
	int i;

	i = -1;
	while (++i < j - 1)
	{
		if (!(wh->e = add_edge(wh->e, wh->tab[x[i]], wh->tab[x[i + 1]])))
		{
			printf("ae1\n");
			return (edgefiller_quit(wh->e));
		}
	}
	if (i > 1)
		if (!(wh->e = add_edge(wh->e, wh->tab[x[0]], wh->tab[x[i]])))
		{
			printf("ae2\n");
			return (edgefiller_quit(wh->e));
		}
	return (wh->e);
}

t_edge			*edgefiller(t_input *f, t_vertex **vt)
{
	t_edge	*e;
	int		x;
	int		y;

	e = NULL;
	y = 0;
	while (y < f->lines)
	{
		x = 0;
		while (x < f->linelen)
		{
			if (x != f->linelen - 1)
				if (!(e = add_edge(e, vt[y * f->linelen + x],\
					vt[y * f->linelen + x + 1])))
					return (edgefiller_quit(e));
			if (y < f->lines - 1)
				if (!(e = add_edge(e, vt[y * f->linelen + x],\
					vt[(y + 1) * f->linelen + x])))
					return (edgefiller_quit(e));
			x++;
		}
		y++;
	}
	return (e);
}
