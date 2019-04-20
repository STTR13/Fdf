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

#include "modeling.h"

/*
** veconvertstart and gridfiller work together. veconvertstart
** will launch gridfiller in order to make a structured list
** with all of the information from file_reader. gridfiller makes
** use of 2 while loops in order to decide the x and y positions
** and uses ft_atoi in order to convert the string to an int.
** it will also use a hexadecimal converter in case of color input
** in the read file. if there is no color input, a base value of
** 255 will be given, which is the color blue.
*/

static t_vertex		*gridfiller(t_input *file, t_vertex *vert, int x, int y)
{
	int		pos;
	int		temp;
	t_ve	v;

	pos = 0;
	y = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			temp = ft_atoi(file->input[pos]);
			if (!(vert = add_vertex(vert, set_ve(temp, -x, y, &v), 0)))
				return (NULL);
			vert->color = ft_hexaconverter(file->input[pos]);
			pos++;
			x++;
		}
		y++;
	}
	return (vert);
}

t_vertex				*veconvertstart(t_input *file)
{
	t_vertex	*vert;
	int		x;
	int		y;

	x = 0;
	y = 0;
	vert = NULL;
	vert = gridfiller(file, vert, x, y);
	return (vert);
}
