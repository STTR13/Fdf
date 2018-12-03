/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorchecker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:11:58 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/03 11:16:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		last_cluster(t_tetri *l)
{
	while (l->next)
		l = l->next;
	if (l->counter == 20)
		return (1);
	return (0);
}

int		checker(char *str, int counter)
{
	int i;
	int blocs;

	i = 0;
	blocs = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (str[i] != '#' && str[i] != '.')
				return (1);
			if ((str[i]) == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (!connections(str))
		return (4);
	return (0);
}

int		connections(char *str)
{
	int i;
	int parts;

	i = 0;
	parts = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				parts++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				parts++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				parts++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				parts++;
		}
		i++;
	}
	return (parts == 6 || parts == 8);
}
