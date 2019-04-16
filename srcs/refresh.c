/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:20:32 by staeter           #+#    #+#             */
/*   Updated: 2019/04/09 14:20:33 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		f1(vertex *vert, void *param)
{
	ve t;

	dot_mv(&((t_wlist*)(param))->sysmat, vert->coord, &t);
	minus(&t, &((t_wlist*)(param))->p.p, &vert->prime);
}

static void		f2(vertex *vert, void *param)
{
	pl tp;
	ve tv[2];

	dot_mv(&((t_wlist*)(param))->sysmat, vert->coord, &tv[0]);
	minus(&tv[0], &((t_wlist*)(param))->p.p, &tv[1]);
	conic_projection(
		&tv[1],
		originsystem(&tp),
		&((t_wlist*)(param))->eye,
		&vert->prime);
}

void			refresh_win(t_wlist *wl)
{
	if (!re_img(wl->w))
		return ;
	system_lmn_matrix(&wl->p, &wl->sysmat);
	(wl->mode) ?
		apply_vertex(&f2, wl->v, (void*)wl) :
		apply_vertex(&f1, wl->v, (void*)wl);
	draw_model(wl->w, wl->e);
	put_img(wl->w);
}
