/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agilmet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:56:06 by agilmet           #+#    #+#             */
/*   Updated: 2018/12/01 12:20:14 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

char		**ft_reset(char **tab, t_tetri *l, t_pos p)
{
	tab[p.y][p.x] = '.';
	tab[p.y + l->p1->y][p.x + l->p1->x] = '.';
	tab[p.y + l->p2->y][p.x + l->p2->x] = '.';
	tab[p.y + l->p3->y][p.x + l->p3->x] = '.';
	return (tab);
}

int			ft_conditions(char ***tab, t_tetri *l, t_pos p, int size)
{
	if (((p.x + l->p1->x) >= 0) && ((p.x + l->p1->x) < size) &&
	((p.y + l->p1->y) >= 0) && ((p.y + l->p1->y) < size) &&
	((p.x + l->p2->x) >= 0) && ((p.x + l->p2->x) < size) &&
	((p.y + l->p2->y) >= 0) && ((p.y + l->p2->y) < size) &&
	((p.x + l->p3->x) >= 0) && ((p.x + l->p3->x) < size) &&
	((p.y + l->p3->y) >= 0) && ((p.y + l->p3->y) < size) &&
	(((*tab)[p.y + l->p1->y][p.x + l->p1->x]) == '.') &&
	(((*tab)[p.y + l->p2->y][p.x + l->p2->x]) == '.') &&
	(((*tab)[p.y + l->p3->y][p.x + l->p3->x]) == '.'))
	{
		((*tab)[p.y][p.x]) = l->c;
		((*tab)[p.y + l->p1->y][p.x + l->p1->x]) = l->c;
		((*tab)[p.y + l->p2->y][p.x + l->p2->x]) = l->c;
		((*tab)[p.y + l->p3->y][p.x + l->p3->x]) = l->c;
		return (1);
	}
	return (0);
}

int			ft_put_tetri(char ***tab, t_tetri *l, int size)
{
	t_pos	p;

	p.y = 0;
	while (p.y < size)
	{
		p.x = 0;
		while (p.x < size)
		{
			if ((*tab)[p.y][p.x] == '.' &&
			ft_conditions(tab, l, p, size))
			{
				if (!(l->next))
					return (1);
				if (!(ft_put_tetri(tab, l->next, size)))
					*tab = ft_reset(*tab, l, p);
				else
					return (1);
			}
			p.x++;
		}
		p.y++;
	}
	return (0);
}

char		**ft_newtab(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if ((tab = ft_memalloc(sizeof(char **) * size)) == NULL)
		return (0);
	while (i < size)
	{
		if (!(tab[i] = ft_strnew(size)))
			return (ft_arrclr(tab));
		ft_memset(tab[i], '.', size);
		i++;
	}
	return (tab);
}

char		**ft_solver(t_tetri *lst, int size)
{
	int		i;
	char	**tab;

	tab = ft_newtab(size);
	while (!(ft_put_tetri(&tab, lst, size)))
	{
		size++;
		if (!(tab = ft_newtab(size)))
			return (ft_arrclr(tab));
	}
	return (tab);
}
