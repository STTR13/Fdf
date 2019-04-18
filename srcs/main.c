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
	warehouse	wh;
	int			filetype;

	if (argc != 2)
		errormessage(1, &wh);
	if (!(filetype = file_read_select(argv[1])))
		errormessage(3, &wh);
	if (filetype == 1)
	{
		if (!(wh.file = file_reader_fdf(open(argv[1], O_RDONLY)))\
		|| !(wh.v = veconvertstart(wh.file))\
		|| !(wh.e = edgefiller(wh.file, wh.v)))
			errormessage(2, &wh);
	}
	else
	{
		if (!(file_reader_obj(open(argv[1], O_RDONLY), &wh)))
			errormessage(2, &wh);
	}
	printf("%d\n", wh.e->vert1->pos);
	printf("%f\n", wh.e->vert1->coord.x);
	printf("%d\n", wh.e->vert2->pos);
	printf("%f\n", wh.e->vert2->coord.x);
	printf("%d\n", wh.e->next->vert1->pos);
	printf("%f\n", wh.e->next->vert1->coord.x);
	printf("%d\n", wh.e->next->vert2->pos);
	printf("%f\n", wh.e->next->vert2->coord.x);
	printf("%d\n", wh.e->next->next->vert1->pos);
	printf("%f\n", wh.e->next->next->vert1->coord.x);
	printf("%d\n", wh.e->next->next->vert2->pos);
	printf("%f\n", wh.e->next->next->vert2->coord.x);
	window_init_load(&wh);
	free_all(&wh);
	return (0);
}
