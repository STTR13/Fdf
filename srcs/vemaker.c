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

vertex	*ampos(twlist *file, int x, int y)
{
	vertex	*vn;

	if ((vn = ft_memalloc(sizeof(vertex))) == NULL)
		return ((void *)NULL);
	if (x - 1 >= 0)
		vn->next[0] = veconvertprev(file, x - 1, y);
	if (x + 1 < file->file->linelen)
		vn->next[1] = veconvert(file, x + 1, y);
	if (y - 1 >= 0)
		vn->next[0] = veconvertprev(file, x, y - 1);
	if (y + 1 < file->file->lines)
		vn->next[1] = veconvert(file, x, y + 1);
	if (x == file->file->linelen && y == file->file->lines)
		return (vn);
	return (vn);
}

vertex	*veconvertprev(twlist *file, int x, int y)
{
	vertex	*vect;

	if ((vect = ft_memalloc(sizeof(vertex))) == NULL)
		return (NULL);
	vect->v.x = x;
	vect->v.y = y;
	vect->v.z = file->file->input[y][x];
	return (vect);
}

vertex	*veconvert(twlist *file, int x, int y)
{
	vertex	*vect;

	if ((vect = ft_memalloc(sizeof(vertex))) == NULL)
		return (NULL);
	vect->v.x = x;
	vect->v.y = y;
	vect->v.z = file->file->input[y][x];
	vect = ampos(file, x, y);
	return (vect);
}
