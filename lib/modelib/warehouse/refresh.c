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

#include "modeling.h"

static void		f1(t_vertex *vert, void *param)
{
	t_ve t;

	minus(
		&vert->coord,
		&((t_warehouse*)(param))->p.p,
		&t
	);
	dot_mv(
		&((t_warehouse*)(param))->sysmat,
		t,
		&vert->prime
	);
}

static t_ve		*conic_projection_s(t_ve *point, t_warehouse *wh, t_ve *ret)
{
	ret->z = 0;
	ret->x = (point->x / (point->z + wh->eye)) * wh->eye;
	ret->y = (point->y / (point->z + wh->eye)) * wh->eye;
	return (ret);
}

static void		f2(t_vertex *vert, void *param)
{
	t_ve tv;

	minus(&vert->coord, &((t_warehouse*)(param))->p.p, &tv);
	dot_mv(&((t_warehouse*)(param))->sysmat, tv, &tv);
	if (tv.z >= 0)
		conic_projection_s(
			&tv,
			(t_warehouse*)(param),
			&vert->prime);
	else
		vert->prime.z = -1;
}

void			refresh_win(t_warehouse *wl)
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
