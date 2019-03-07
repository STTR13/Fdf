/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/06 13:37:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*vertex	*ampos(tinput *file, int x, int y)
{
	vertex	*vn;

	if ((vn = ft_memalloc(sizeof(vertex))) == NULL)
		return ((void *)NULL);
	if (x == file->linelen && y == file->lines)
		return (vn);
	if (x - 1 >= 0)
		vn->next[0] = veconvertprev(file, x - 1, y);
	if (x + 1 < file->linelen)
		vn->next[1] = veconvert(file, x + 1, y);
	if (y - 1 >= 0)
		vn->next[0] = veconvertprev(file, x, y - 1);
	if (y + 1 < file->lines)
		vn->next[1] = veconvert(file, x, y + 1);

	return (vn);
}*/

/*vertex	*veconvertprev(tinput *file, int x, int y)
{
	vertex	*vect;

	if ((vect = ft_memalloc(sizeof(vertex))) == NULL)
		return (NULL);
	vect->v.x = x;
	vect->v.y = y;
	vect->v.z = file->input[y][x];
	return (vect);
}*/

ve *createv(tinput *file, int x, int y, ve *v)
{
	v->x = x;
	v->y = y;
	v->z = file->input[y][x];
	return (v);
}

vertex *backfiller(tinput *file, vertex *grid, int x, int y)
{
	vertex *temp;

	if (x > 0)
	{
	temp = grid - 1;
	grid->next[2] = temp;
	backfiller(file, grid->next[2], x - 1, y);
	}
	if (y > 0)
	{
	temp = grid - file->linelen;
	grid->next[3] = temp;
	backfiller(file, grid->next[3], x, y - 1);
	}
	return (grid);
}

vertex *nextfiller(tinput *file, vertex *grid, int x, int y)
{
	vertex *temp;

	if (x < file->linelen)
	{
	temp = grid + 1;
	grid->next[0] = temp;
	nextfiller(file, grid->next[0], x + 1, y);
	}
	if (y < file->lines)
	{
	temp = grid + file->linelen;
	grid->next[1] = temp;
	nextfiller(file, grid->next[1], x, y + 1);
	}
	/*if (grid->v.x > 0)
	{
	temp = grid - 1;
	grid->next[2] = temp;
	//nextfiller(file, grid->next[2], x - 1, y);
	}
	if (grid->v.y > 0)
	{
	temp = grid - file->linelen;
	grid->next[3] = temp;
}*/
	return (grid);
}

vertex	*veconvertstart(tinput *file, int x, int y)
{
	ve v;
	vertex	*vect;
	vertex *temp;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			vect = new_vertex(*createv(file, x, y, &v));
			x++;
		}
		y++;
	}
	int i = file->lines * file->linelen;
	while (--i > 0)
		vect--;
	return (vect);
}
