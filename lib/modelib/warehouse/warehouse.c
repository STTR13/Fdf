/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warehouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:24:33 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:24:35 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

void		init_warehouse(warehouse *wh)
{
	wh->w = new_window("FDF", 5120 / 2, 2880 / 2);
	wh->p.n.x = 1;
	wh->p.n.y = 1;
	wh->p.n.z = -1;
	unit(&wh->p.n, &wh->p.n);
	wh->p.p.x = 0;
	wh->p.p.y = 0;
	wh->p.p.z = 0;
	set_lm(&wh->p, 1);
	wh->eye = 200;
	wh->mode = 0;
	wh->mouse = true;
}

static void	free_i(t_input *file)
{
	if (file->input)
		ft_chararrclr(file->input, file->linelen * file->lines);
	file->lines = 0;
	file->linelen = 0;
	free(file);
}

void		free_all(warehouse *wh)
{
	if (wh->w)
		free_window(wh->w);
	if (wh->e)
		free_edge(&wh->e);
	if (wh->v)
		free_vertex(&wh->v);
	if (wh->file)
		free_i(wh->file);
}
