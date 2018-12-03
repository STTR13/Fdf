/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 14:12:46 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/02 14:58:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

t_tetri	*piece_creator(t_tetri *begin, char *buffer, char cl, int counter)
{
	t_tetri	*tetris;

	if (!(begin->p1))
		tetris = begin;
	else
	{
		if ((tetris->next = \
		(t_tetri *)ft_memalloc(sizeof(t_tetri))) == NULL)
			return (NULL);
		tetris = tetris->next;
	}
	if (checker(buffer, counter) != 0
		|| (tetris = new_piece(buffer, cl, tetris, counter)) == NULL)
		return (NULL);
	return (begin);
}

t_tetri	*list_creator(t_tetri *begin, int fd)
{
	char	*buffer;
	int		counter;
	int		i;
	char	cl;

	cl = 'A';
	i = 0;
	if ((buffer = ft_strnew(21)) == NULL)
		return (NULL);
	while ((counter = read(fd, buffer, 21)) >= 20)
	{
		if ((begin = piece_creator(begin, buffer, cl, counter)) == NULL)
			return (delete_pieces(begin));
		cl++;
		i++;
	}
	ft_strdel(&buffer);
	if (i < 1)
		return (NULL);
	else if (i > 26)
		return (delete_pieces(begin));
	if (last_cluster(begin) == 1 && counter == 0)
		return (begin);
	return (delete_pieces(begin));
}

t_tetri	*file_reader(int fd)
{
	t_tetri *begin;

	if ((begin = (t_tetri *)ft_memalloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	begin = list_creator(begin, fd);
	return (begin);
}
