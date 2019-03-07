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
	ve ve;
	int i;
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
	int x = 0, y = 0;
	while (y < window.file->lines)
	{
		x = 0;
		while (x < window.file->linelen)
		{
			printf("%i, ", window.file->input[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	v = veconvertstart(window.file, 0, 0);
//
/*while (i < window.file->lines * window.file->linelen)
	{
		printf("\nx: %f, y: %f, z: %f\n", v->v.x, v->v.y, v->v.z);
		v++;
		i++;
	}*/
//

	//window_init(&window);
}
