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

ve createv(tinput *file, int x, int y)
{
	ve v;

	v.x = x;
	v.y = y;
	v.z = file->input[y][x];
	return (v);
}

vertex *veconverter(tinput *file, int x, int y, vertex *grid)
{
	ve curr;
	ve prev;
	if (x < file->linelen)
	{
		x = 0;
		y++;
	}
	if (y < file->lines)
		return (grid);
	curr = createv(file, x, y);
	printf("\n\n%i\n\n", file->input[y][x]);
printf("\nx: %f\ny: %f\nz: %f\n",curr.x,curr.y,curr.z);
	prev = grid->v;
	return(add_vertex(grid, curr, prev));

}

vertex	*veconvertstart(tinput *file, int x, int y)
{
	ve curr;
	vertex	*vect;
	bool ret;
	ret = 0;
	curr = createv(file, x, y);
	vect = new_vertex(curr);
	ret = veconverter(file, x + 1, y, vect);
	printf("%i\n", ret);
	return (vect);
}
