/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:58:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:48:40 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** frees every malloc
*/

static void	free_i(t_input *file)
{
	if (file->input)
		ft_chararrclr(file->input, file->linelen * file->lines);
	file->lines = 0;
	file->linelen = 0;
	free(file);
}

void		free_all(warehouse *w)
{
	if (w->w)
		free_window(w->w);
	if (w->e)
		free_edge(&w->e);
	if (w->v)
		free_vertex(&w->v);
	if (w->file)
		free_i(w->file);
}

void		errormessage(int i, warehouse *window)
{
	if (i == 1)
	{
		ft_putendl("usage: ./fdf input_file");
		exit(0);
	}
	else if (i == 2)
	{
		free_all(window);
		ft_putendl("error");
		exit(0);
	}
}
