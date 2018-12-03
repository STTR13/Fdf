/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leak_cleaner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:54:05 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/02 16:29:22 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_arrclr(char **ap)
{
	int i;

	i = ft_strlen(ap[0]) - 1;
	if (*ap && ap)
	{
		while (i > -1)
		{
			free(ap[i]);
			ap[i] = NULL;
			i--;
		}
	}
	return (ap);
}

void		ft_memdell(void *ap)
{
	if (ap)
	{
		free(ap);
		ap = NULL;
	}
}

t_tetri		*delete_pieces(t_tetri *begin)
{
	while (begin)
	{
		if (begin != NULL)
		{
			begin->c = NULL;
			begin->counter = NULL;
			ft_memdell((void *)begin->p0);
			ft_memdell((void *)begin->p1);
			ft_memdell((void *)begin->p2);
			ft_memdell((void *)begin->p3);
		}
		begin = begin->next;
	}
	return (begin);
}
