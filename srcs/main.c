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

int main(int argc, char **argv)
{
	t_wlist window;
	vertex *v;
	while (1)
	{
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	if ((window.file = file_reader(open(argv[1], O_RDONLY))) == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	if (!(v = veconvertstart(window.file, 0, 0)))
	{
		ft_putendl("error");
		return (0);
	}
	//window_init(&window);
	//ft_intarrprint(window.file->input, window.file->linelen, window.file->lines);
	free_all(v, window.file);
}
	return (0);
}
