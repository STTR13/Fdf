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

#include "fdf.h"

static int	file_read_select(char *str)
{
	if (ft_strcmp(ft_strrchr(str, '.'), ".fdf") == 0)
		return (1);
	else if (ft_strcmp(ft_strrchr(str, '.'), ".obj") == 0)
		return (2);
	return (0);
}

int			main(int argc, char **argv)
{
	t_warehouse	wh;
	int			filetype;

	if (argc != 2)
		errormessage(1, &wh);
	if (!(filetype = file_read_select(argv[1])))
		errormessage(3, &wh);
	if (filetype == 1)
	{
		if (!(wh.file = file_reader_fdf(open(argv[1], O_RDONLY)))\
		|| !(wh.v = veconvertstart(wh.file))\
		|| !(wh.tab = new_vertex_tab(wh.v, wh.file->lines * wh.file->linelen))\
		|| !(wh.e = edgefiller(wh.file, wh.tab)))
			errormessage(2, &wh);
	}
	else
	{
		if (!(file_reader_obj(open(argv[1], O_RDONLY), &wh)))
			errormessage(2, &wh);
	}
	window_init_load(&wh);
	free_all(&wh);
	return (0);
}
