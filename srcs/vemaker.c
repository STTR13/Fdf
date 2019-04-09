/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:47:26 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

ve					createv(int z, int x, int y)
{
	ve v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

static vertex		*gridfiller(t_input *file, vertex *vert)
{
	int pos;
	int temp;
	int x;
	int y;

	pos = 0;
	y = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			temp = ft_atoi(file->input[pos]);
			if (!(vert = add_vertex(vert, createv(temp, x, y))))
				return (NULL);
			vert->color = ft_hexaconverter(file->input[pos]);
			pos++;
			x++;
		}
		y++;
	}
	return (vert);
}

vertex				*veconvertstart(t_input *file)
{
	vertex	*vert;

	vert = NULL;
	vert = gridfiller(file, vert);
	return (vert);
}
