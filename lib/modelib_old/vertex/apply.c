/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:36:59 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 12:37:01 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

static void		apply_vertex_sub(void (*f)(vertex *vert), vertex *grid)
{
	short	i;

	if (!grid || grid->done)
		return ;
	(*f)(grid);
	grid->done = true;
	i = -1;
	while (++i < 4)
		apply_vertex_sub(f, grid->next[i]);
}

void			apply_vertex(void (*f)(vertex *vert), vertex *grid)
{
	apply_vertex_sub(f, grid);
	reset_vertex(grid);
}

static void		reset_vertex_sub(vertex *vert, short count)
{
	short i;

	if (vert->done)
	{
		vert->done = false;
		count = 6;
	}
	else
		count--;
	if (!count)
		return ;
	i = -1;
	while (++i < 4)
		if (vert->next[i])
			reset_vertex_sub(vert->next[i], count);
}

void			reset_vertex(vertex *grid)
{
	reset_vertex_sub(grid, 6);
}
