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
	/*int i;
	i = -1;
	while (++i < window.file->linelen * window.file->lines)
	{
		printf("x: %f\ny: %f\nz: %f\ncolor: %i\n", v->v.x, v->v.y, v->v.z, v->color);
		if (v->next[0])
			printf("Vector to the right: x: %f, y: %f, z: %f\n", v->next[0]->v.x, v->next[0]->v.y, v->next[0]->v.z);
		if (v->next[1])
			printf("Vector to the bottom: x: %f, y: %f, z: %f\n", v->next[1]->v.x, v->next[1]->v.y, v->next[1]->v.z);
		if (v->next[2])
			printf("Vector to the left: x: %f, y: %f, z: %f\n", v->next[2]->v.x, v->next[2]->v.y, v->next[2]->v.z);
		if (v->next[3])
			printf("Vector to the top: x: %f, y: %f, z: %f\n", v->next[3]->v.x, v->next[3]->v.y, v->next[3]->v.z);
		printf("\n");
		v++;
	}*/
	window_init(&window);
	free_all(&window);
	return (0);
}
