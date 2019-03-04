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

ve *veconvert(int **input, int lines, int linelen)
{
	ve *vector;
	t_list *list;
	int x;
	int y;
	x = 0;
	printf("lines: %i, linelen: %i\n", lines, linelen);

	while (x < lines)
	{
		y = 0;
		while (y < linelen)
		{
			if (x != lines - 1 || y != linelen - 1)
			{
				if ((vector = (ve *)ft_memalloc(sizeof(ve))) == NULL)
					return (NULL);
				vector->x = x;
				vector->y = y;
				vector->z = input[x][y];
				ft_lstadd(&list, ft_lstnew(vector, sizeof(ve)));
				ft_memdel((void **)&vector)
			}
			y++;
		}
		x++;
	}
	return (list);
}
