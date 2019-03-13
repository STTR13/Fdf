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
	vertex	*v;

	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	if ((window.file = file_reader(open(argv[1], O_RDONLY))) == NULL)
	{
		if (window.file != NULL)
			ft_memdell(window.file);
		ft_putendl("error");
		return (0);
	}
	if (!(v = veconvertstart(window.file, 0, 0)))
	{
		free_all(v, window.file);
		ft_putendl("error");
		return (0);
	}
	int i = window.file->linelen * window.file->lines;
	while (--i)
	{
		printf("x: %f\ny: %f\nz: %f\ncolor: %i\n", v->v.x, v->v.y, v->v.z, v->color);
		v++;
	}
	//window_init(&window);
	//free_all(v, window.file);
	return (0);
}
