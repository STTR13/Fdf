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

static vertex		*vertex_link(t_input *file, vertex *vect)
{
	int i;

	i = file->lines * file->linelen;
	while (--i >= 0)
		vect--;
	i = file->lines * file->linelen;
	while (--i >= 0)
	{
		xlink(vect, file);
		ylink(vect, file);
		vect++;
	}
	i = file->lines * file->linelen;
	while (--i >= 0)
		vect--;
	return (vect);
}

static vertex		*gridfiller(t_input *file, int x, int y, vertex *vect)
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
			if (!(vect = new_vertex(createv(temp, x, y), vect)))
				return (NULL);
			vect->color = hexaconv(file->input[pos]);
			pos++;
			vect++;
			x++;
		}
		y++;
	}
	return (vect);
}

vertex				*veconvertstart(t_input *file, int x, int y)
{
	vertex	*vect;

	if (!(vect = new_grid(file)))
		return (NULL);
	vect = gridfiller(file, x, y, vect);
	vect = vertex_link(file, vect);
	return (vect);
}
