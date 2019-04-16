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

# include "fdf.h"

#include <stdio.h> //(t)

static void		f1(vertex *vert, void *param)
{
	ve t;

	//printf("f1\n");
	minus(&vert->coord, &((t_wlist*)(param))->p.p, &t);
	dot_mv(&((t_wlist*)(param))->sysmat, t, &vert->prime);
}

static void		f2(vertex *vert, void *param)
{
	pl tp;
	ve tv;

	//printf("f2\n");
	minus(&vert->coord, &((t_wlist*)(param))->p.p, &tv);
	dot_mv(&((t_wlist*)(param))->sysmat, tv, &tv);
	conic_projection(
		&tv,
		originsystem(&tp),
		&((t_wlist*)(param))->eye,
		&vert->prime
	);
}

void			refresh_win(t_wlist *wl)
{
	printf("refresh\n");
	if (!re_img(wl->w))
		return ;
	system_lmn_matrix(&wl->p, &wl->sysmat);
	//printf("lmn ok %d\n", wl->mode);
	(wl->mode) ?
		apply_vertex(&f2, wl->v, (void*)wl) :
		apply_vertex(&f1, wl->v, (void*)wl);
	//printf("apply vertex done\n");
	draw_model(wl->w, wl->e);
	//printf("draw model done\n");
	put_img(wl->w);
	//printf("put img done\n");
}
