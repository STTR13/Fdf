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
	(void)argv;
	if (argc != 2)
	{
		ft_putstr("usage: ./fdf input_file\n");
		return (0);
	}
	if ((window.file = file_reader(open(argv[1], O_RDONLY))) == NULL)
	{
		if (window.file != NULL)
			free_all(&window);
		ft_putendl("error");
		return (0);
	}
	if ((window.v = veconvertstart(window.file, 0, 0)) == NULL)
	{
		free_all(&window);
		ft_putendl("error");
		return (0);
	}
	window.test = new_window("FDF", 1000, 1000);
	window.test->hook.param = &window;
	window.test->hook.key_release = &key_press_all;
	window.test->hook.mouse_press = &mouse_key;
	window.test->hook.close = &windowclose;
	loop(window.test);
	//window_init(&window);
	free_all(&window);
	return (0);
}
