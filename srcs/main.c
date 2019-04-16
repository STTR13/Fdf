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
	warehouse	window;

	if (argc != 2)
		errormessage(1, &window);
	if (!(window.file = file_reader(open(argv[1], O_RDONLY)))\
	|| !(window.v = veconvertstart(window.file))\
	|| !(window.e = edgefiller(window.file, window.v)))
		errormessage(2, &window);
	window_init_load(&window);
	free_all(&window);
	return (0);
}
