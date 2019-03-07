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

ve createv(tinput *file, int x, int y, ve v)
{
	v.x = x;
	v.y = y;
	v.z = file->input[y][x];
	return (v);
}

vertex *gridmaker(tinput *file)
{
	vertex *rvert;

	if (!(rvert = (vertex*)malloc(sizeof(vertex) * (file->lines * file->linelen))))
		return (NULL);
	return (rvert);
}

vertex	*veconvertstart(tinput *file, int x, int y)
{
	ve v;
	vertex	*vect;
	vertex *temp;
	//vect = gridmaker(file);
	int j = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			vect = new_vertex(createv(file, x, y, v));
			vect++;
			x++;
		}
		y++;
	}
/*if (0 < x)
{
	temp = vect - 1;
	vect->next[0] = temp;
}
if (x == 0)
{
	temp = vect + 1;
	vect->next[0] = temp;
}
if (y > 0 && y < file->lines)
{
	temp = vect - file->linelen;
	vect->next[1] = temp;
}
if (y == 0)
{
	temp = vect + file->linelen;
	vect->next[1] = temp;
}*/
	int i = file->lines * file->linelen;
	while (--i >= 1)
	{
		//link_vertex(vect, vect-1);
		vect--;
	}
	/*vect += file->linelen * 80;
printf("\n%i\n", j);*/
	return (vect);
}
