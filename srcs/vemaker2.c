/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vemaker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:17:08 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/15 12:17:10 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

ve		createv(int z, int x, int y)
{
	ve v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

void	xlink(vertex *grid, t_input *file)
{
	vertex	*temp;

	if (0 < grid->v.x)
	{
		temp = grid - 1;
		grid->next[2] = temp;
	}
	if (grid->v.x == 0 || grid->v.x < file->linelen - 1)
	{
		temp = grid + 1;
		grid->next[0] = temp;
	}
}

void	ylink(vertex *grid, t_input *file)
{
	vertex	*temp;

	if (grid->v.y > 0)
	{
		temp = grid - file->linelen;
		grid->next[3] = temp;
	}
	if (grid->v.y == 0 || grid->v.y < file->lines - 1)
	{
		temp = grid + file->linelen;
		grid->next[1] = temp;
	}
}

char	*hexaconv(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
		{
			temp = ft_strnew(ft_strlen(&str[i + 1]));
			return (ft_strcpy(temp, &str[i + 1]));
		}
		i++;
	}
	return (NULL);
}
