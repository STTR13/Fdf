/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:30:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 16:25:18 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_wlist	window;

	if (argc != 2)
	{
		ft_putendl("usage: ./fdf input_file");
		return (0);
	}
	if (!(window.file = file_reader(open(argv[1], O_RDONLY))) || \
	!(window.v = veconvertstart(window.file))  || \
	!(window.e = edgefiller(window.file, window.v)))
	{
		if (window.file != NULL)
			free_all(&window);
		ft_putendl("error");
		return (0);
	}
	window_init_load(&window);
	return (0);
}
