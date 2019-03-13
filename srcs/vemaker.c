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

static ve		createv(t_input *file, int x, int y)
{
	ve v;

	v.x = x;
	v.y = y;
	v.z = file->input[y][x];
	return (v);
}

static void		xlink(vertex *grid, t_input *file)
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

static void		ylink(vertex *grid, t_input *file)
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

static vertex	*new_grid(t_input *file)
{
	vertex *rvert;

	rvert = NULL;
	if (!(rvert = (vertex*)malloc(sizeof(vertex) \
		* (file->lines * file->linelen))))
		return (NULL);
	return (rvert);
}

static void color_endian(char *str, vertex *grid)
{
	int temp;

	temp = ft_hexaconverter(str);
	grid->color = temp;
}

vertex			*veconvertstart(t_input *file, int x, int y)
{
	vertex	*vect;
	int		i;

	if (!(vect = new_grid(file)))
		return (NULL);
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
		//color_endian(file->color[i], vect);
		vect--;
	}
	return (vect);
}
