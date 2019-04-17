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

static int	file_read_select(char *str)
{
	int i;

	i = ft_strlen(str);
	i--;
	if (str[i] == 'f')
		return (1);
	else if (str[i] == 'j')
		return (2);
	return (0);
}

int			main(int argc, char **argv)
{
	warehouse	window;
	int			filetype;

	if (argc != 2)
		errormessage(1, &window);
	if (!(filetype = file_read_select(argv[1])))
		errormessage(3, &window);
	if (filetype == 1)
	{
		if (!(window.file = file_reader_fdf(open(argv[1], O_RDONLY)))\
		|| !(window.v = veconvertstart(window.file))\
		|| !(window.e = edgefiller(window.file, window.v)))
			errormessage(2, &window);
	}
	else
	{
		//window.v = file_reader_obj(open(argv[1], O_RDONLY));
	}
	window_init_load(&window);
	free_all(&window);
	return (0);
}
