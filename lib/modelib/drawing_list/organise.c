/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organise.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 12:52:25 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 12:52:26 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

static bool		organise_sub(drawing_list *dl, vertex *grid)
{
	short i;

	if (!grid || grid->done)
		return (true);
	grid->done = true;
	if (!insert_drawing_list(&dl, grid))
		return (false);
	i = -1;
	while (++i < 4)
		if (!organise_sub(dl, grid->next[i]))
			return (false);
	return (true);
}

drawing_list	*organise(vertex *grid)
{
	drawing_list *r;
	short i;

	if (!(r = new_drawing_list(grid)))
		return (NULL);
	grid->done = true;
	i = -1;
	while (++i < 4)
		if (!organise_sub(r, grid->next[i]))
		{
			reset_vertex(grid);
			return (NULL);
		}
	reset_vertex(grid);
	return (r);
}

static void		reorganise_sub(drawing_list *dl, bool *done)
{
	drawing_list *t;

	if (!dl->next || !dl->next->next)
		return ;
	if (dl->next->next->vert->v.x < dl->next->vert->v.x)
	{
		t = dl->next;
		dl->next = t->next;
		t->next = dl->next->next;
		dl->next->next = t;
		*done = false;
	}
	reorganise_sub(dl->next, done);
}

void			reorganise(drawing_list **dl)
{
	bool b;
	drawing_list *t;

	if (!dl || !*dl)
		return ;
	b = false;
	while (!b)
	{
		b = true;
		if ((*dl)->next && (*dl)->vert->v.x > (*dl)->next->vert->v.x)
		{
			b = false;
			t = *dl;
			*dl = t->next;
			t->next = (*dl)->next;
			(*dl)->next = t;
		}
		reorganise_sub(*dl, &b);
	}
}
