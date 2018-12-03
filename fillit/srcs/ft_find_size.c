/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:50:35 by agilmet           #+#    #+#             */
/*   Updated: 2018/12/01 12:17:44 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_calculate_bis(int count)
{
	if (count == 3 || count == 4)
		return (4);
	if (count == 5 || count == 6)
		return (5);
	if (count <= 9)
		return (6);
	if (count <= 12)
		return (7);
	if (count <= 16)
		return (8);
	if (count <= 20)
		return (9);
	if (count <= 25)
		return (10);
	if (count == 26)
		return (11);
	return (0);
}

int		ft_calculate(int count, t_tetri *l)
{
	if (count == 1)
	{
		if (l->p3->x == 3 || l->p3->y == 3)
			return (4);
		if (l->p1->x == 1 && l->p2->y == 1 && l->p3->x == 1 && l->p3->y == 1)
			return (2);
		else
			return (3);
	}
	if (count == 2)
	{
		if (((l->p3->x == 3 || l->p3->y == 3)) || ((l->p1->x == 1 &&
		l->p2->y == 1 && l->p3->x == 1 && l->p3->y == 1) &&
		(l->next->p1->x == 1 && l->next->p2->y == 1 &&
		l->next->p3->x == 1 && l->next->p3->y == 1)))
			return (4);
		else
			return (3);
	}
	else
		return (ft_calculate_bis(count));
}

int		ft_find_size(t_tetri *l)
{
	t_tetri *begin;
	int		count;

	count = 1;
	begin = l;
	while (l->next)
	{
		count++;
		l = l->next;
	}
	if (count < 1 || count > 26)
		return (0);
	l = begin;
	count = ft_calculate(count, l);
	return (count);
}
