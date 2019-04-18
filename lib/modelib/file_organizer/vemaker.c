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
** createv will take the read information together with positions x
** and y in order to create a new vector
*/

ve					*createv(double z, double x, double y, ve *ret)
{
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}

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

static vertex		*gridfiller(t_input *file, vertex *vert, int x, int y)
{
	int pos;
	int temp;
	ve	v;

	pos = 0;
	y = 0;
	while (y < file->lines)
	{
		x = 0;
		while (x < file->linelen)
		{
			temp = ft_atoi(file->input[pos]);
			if (!(vert = add_vertex(vert, createv(temp, -x, y, &v), 0)))
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
	int		x;
	int		y;

	x = 0;
	y = 0;
	vert = NULL;
	vert = gridfiller(file, vert, x, y);
	return (vert);
}
