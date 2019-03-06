/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:59:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/04 16:59:24 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

vertex ampos(tinput *file, int x, int y)
{
	int points;

	points = 0;
	if (x - 1 >= 0)
		points++;
	if (x + 1 < file->linelen)
		points++;
	if (y - 1 >= 0)
		points++;
	if (y + 1 < file->lines)
		points++;
	if ()
	return (points);
}
vertex *veconvert(twlist *file)
{
	vertex *v;
	int positions;

	if ((v = ft_memalloc(sizeof(vertex))) == NULL)
		return (0);
	positions = ampos(file->file, 0, 0);
	return (NULL);
}
