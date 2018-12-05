/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 10:46:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/03 11:16:31 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

/*
** The main for our program checks if the user input is correct.
** If there is an incorrect usage of fillit, it will display
** a message telling the user how to use the program.
** On correct usage of the program, the file_reader function
** will read the file the user gave as input and check if it
** can be used by fillit.
*/

int	main(int argc, char **argv)
{
	char	**map;
	t_tetri	*lst;
	int		size;

	if (argc != 2)
	{
		ft_putendl("usage: fillit input_file");
		return (0);
	}
	if ((lst = file_reader(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(size = ft_find_size(lst)))
	{
		ft_putendl("error");
		return (0);
	}
	map = ft_solver(lst, size);
	printmap(map);
	lst = delete_pieces(lst);
	ft_arrclr(map);
	return (0);
}
