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
	twlist window;
	vertex *v;

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
	v += window.file->linelen + 1;
	printf("PREVIOUS POSITION X: %f, Y: %f, Z: %f\n", v->v.x, v->v.y, v->v.z);
	v += 1;
	printf("CURRENT POSITION X: %f, Y: %f, Z: %f\n", v->v.x, v->v.y, v->v.z);
	printf("VECTOR TO THE RIGHT X: %f, Y: %f, Z: %f\n", v->next[0]->v.x, v->next[0]->v.y, v->next[0]->v.z);
	printf("VECTOR TO THE BOTTOM X: %f, Y: %f, Z: %f\n", v->next[1]->v.x, v->next[1]->v.y, v->next[1]->v.z);
	printf("VECTOR TO THE LEFT X: %f, Y: %f, Z: %f\n", v->next[2]->v.x, v->next[2]->v.y, v->next[2]->v.z);
	printf("VECTOR TO THE TOP X: %f, Y: %f, Z: %f\n", v->next[3]->v.x, v->next[3]->v.y, v->next[3]->v.z);
	/*int i;
	i = 0;*/
	/*while (i < window.file->lines * window.file->linelen)
	{
		printf("X: %f, Y: %f, Z: %f\n", v->v.x, v->v.y, v->v.z);
		v++;
		i++;
	}*/
	//window_init(&window);
}
