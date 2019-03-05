/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:44:29 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 12:44:30 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

vertex			*find_vertex(ve v, vertex *grid)
{
	short	i;
	vertex	*t;

	if (!grid->done)
		return (NULL);
	if (equal_v(grid->v, v))
	{
		reset_vertex(grid);
		return (grid);
	}
	grid->done = true;
	i = -1;
	while (++i < 4)
		if ((t = find_vertex(v, grid->next[i])))
			return (t);
	return (NULL);
}
