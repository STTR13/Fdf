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

static vertex		*new_grid(t_input *file)
{
	vertex *rvert;

	rvert = NULL;
	if (!(rvert = (vertex*)malloc(sizeof(vertex) \
		* (file->lines * file->linelen + 1))))
		return (NULL);
	return (rvert);
}

static vertex		*vertex_link(t_input *file, vertex *vert)
{
	int i;

	i = file->lines * file->linelen;
	while (--i >= 0)
		vert--;
	i = file->lines * file->linelen;
	while (--i >= 0)
	{
		xlink(vert, file);
		ylink(vert, file);
		vert++;
	}
	i = file->lines * file->linelen;
	while (--i >= 0)
		vert--;
	return (vert);
}

static vertex		*gridfiller(t_input *file, int x, int y, vertex *vert)
{
	int pos;
	int temp;

	pos = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			temp = ft_atoi(file->input[pos]);
			if (!(vert = new_vertex(createv(temp, x, y), vert)))
				return (NULL);
			vert->color = hexaconv(file->input[pos]);
			pos++;
			vert++;
			x++;
		}
		y++;
	}
	return (vert);
}

vertex				*veconvertstart(t_input *file, int x, int y)
{
	vertex	*vert;

	if (!(vert = new_grid(file)))
		return (NULL);
	vert = gridfiller(file, x, y, vert);
	vert = vertex_link(file, vert);
	return (vert);
}
