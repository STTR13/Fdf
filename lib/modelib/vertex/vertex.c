/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:42:33 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 12:42:35 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

vertex			*new_vertex(ve v, vertex *rvert)
{
	rvert->v.x = v.x;
	rvert->v.y = v.y;
	rvert->v.z = v.z;
	rvert->next[0] = NULL;
	rvert->next[1] = NULL;
	rvert->next[2] = NULL;
	rvert->next[3] = NULL;
	rvert->done = true;
	return (rvert);
}

bool			add_vertex(vertex *grid, ve new_vert, ve link)
{
	vertex *nv;

	nv = NULL;
	if (!(grid = find_vertex(link, grid)) || !(nv = new_vertex(new_vert, nv)))
		return (false);
	link_vertex(nv, grid);
	return (true);
}

void			rm_vertex(vertex *to_rm)
{
	short i;

	i = -1;
	while (++i < 4)
		rmlink_vertex(to_rm->next[i], to_rm);
	free(to_rm);
}
