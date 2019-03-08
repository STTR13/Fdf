/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/07 14:54:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

ve			createv(tinput *file, int x, int y)
{
	ve v;

	v.x = x;
	v.y = y;
	v.z = file->input[y][x];
	return (v);
}

void		xlink(vertex *grid, tinput *file)
{
	vertex	*temp;

	if (0 < grid->v.x)
	{
		temp = grid - 1;
		grid->next[2] = temp;
	}
	if (grid->v.x == 0 || grid->v.x < file->linelen)
	{
		temp = grid + 1;
		grid->next[0] = temp;
	}
}

void		ylink(vertex *grid, tinput *file)
{
	vertex	*temp;

	if (grid->v.y > 0)
	{
		temp = grid - file->linelen;
		grid->next[3] = temp;
	}
	if (grid->v.y == 0 || grid->v.y < file->lines)
	{
		temp = grid + file->linelen;
		grid->next[1] = temp;
	}
}

vertex		*new_grid(tinput *file)
{
	vertex *rvert;

	rvert = NULL;
	if (!(rvert = (vertex*)malloc(sizeof(vertex) \
		* (file->lines * file->linelen))))
		return (NULL);
	return (rvert);
}

vertex		*veconvertstart(tinput *file, int x, int y)
{
	vertex	*vect;
	int		i;

	vect = new_grid(file);
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			if (!(vect = new_vertex(createv(file, x, y), vect)))
				return (NULL);
			vect++;
			x++;
		}
		y++;
	}
	i = file->lines * file->linelen;
	while (--i >= 0)
	{
		xlink(vect, file);
		ylink(vect, file);
		vect--;
	}
	return (vect);
}
