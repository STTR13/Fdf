/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_maker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:08:28 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/03 11:17:28 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri		*ft_put_position(t_tetri *piece, t_pos *pos, int count)
{
	if (count == 1)
	{
		piece->p0->x = pos->x;
		piece->p0->y = pos->y;
	}
	if (count == 2)
	{
		piece->p1->x = pos->x - piece->p0->x;
		piece->p1->y = pos->y - piece->p0->y;
	}
	if (count == 3)
	{
		piece->p2->x = pos->x - piece->p0->x;
		piece->p2->y = pos->y - piece->p0->y;
	}
	if (count == 4)
	{
		piece->p3->x = pos->x - piece->p0->x;
		piece->p3->y = pos->y - piece->p0->y;
	}
	return (piece);
}

t_tetri		*insert_piece(char **arr, t_tetri *piece)
{
	int		count;
	t_pos	*pos;

	pos = ft_memalloc(sizeof(t_pos));
	pos->x = 0;
	pos->y = 0;
	count = 0;
	while (pos->y < 4)
	{
		while (pos->x < 4)
		{
			if (arr[pos->y][pos->x] == '#')
			{
				count++;
				piece = ft_put_position(piece, pos, count);
			}
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
	ft_memdell(pos);
	return (piece);
}

t_tetri		*new_piece(char *str, char value, t_tetri *piece, int counter)
{
	int		i;
	int		j;
	char	**arr;

	i = 0;
	j = 0;
	arr = ft_memalloc(sizeof(char **) * 5);
	while (i < 4 && j != 20)
	{
		arr[i] = ft_strnew(5);
		ft_strncpy(arr[i], str + j, 5);
		i++;
		j += 5;
	}
	piece->counter = counter;
	piece->p0 = ft_memalloc(sizeof(t_pos));
	piece->p1 = ft_memalloc(sizeof(t_pos));
	piece->p2 = ft_memalloc(sizeof(t_pos));
	piece->p3 = ft_memalloc(sizeof(t_pos));
	piece = insert_piece(arr, piece);
	piece->p0->x = 0;
	piece->p0->y = 0;
	piece->c = value;
	ft_arrclr(arr);
	return (piece);
}
