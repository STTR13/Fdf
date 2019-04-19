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

static void		f1(vertex *vert, void *param)
{
	ve t;

	//printf("f1\n");
	minus(
		&vert->coord,
		&((warehouse*)(param))->p.p,
		&t
	);
	dot_mv(
		&((warehouse*)(param))->sysmat,
		t,
		&vert->prime
	);
}

static ve		*conic_projection_s(ve *point, warehouse *wh, ve *ret)
{
	ret->z = 0;
	ret->x = (point->x / (point->z + wh->eye)) * wh->eye;
	ret->y = (point->y / (point->z + wh->eye)) * wh->eye;
	return (ret);
}

static void		f2(vertex *vert, void *param)
{
	ve tv;

	//printf("f2\n");
	minus(&vert->coord, &((warehouse*)(param))->p.p, &tv);
	dot_mv(&((warehouse*)(param))->sysmat, tv, &tv);
	if (tv.z >= 0)
		conic_projection_s(
			&tv,
			(warehouse*)(param),
			&vert->prime);
	else
		vert->prime.z = -1;
}

void			refresh_win(warehouse *wl)
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
