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

#include "../includes/fdf.h"

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

/*static ve		*conic_projection_s(ve *point, warehouse *wh, ve *ret)
{
	double	a, b;
	ve		tv;

	a = dot_vv(minus(point, &wh->p->p, &tv), &wh->p->n);
	b = dot_vv(minus(wh->eye, &wh->p->p, &tv), &wh->p->n);
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (nullvector(ret));
	a = abs_s(a);
	b = abs_s(b);
	plus(point, scal_v(minus(point, wh->eye, &tv), a / (a + b), &tv), ret);
	return (ret);
}*/

static void		f2(vertex *vert, void *param)
{
	pl tp;
	ve tv;

	//printf("f2\n");
	minus(&vert->coord, &((warehouse*)(param))->p.p, &tv);
	dot_mv(&((warehouse*)(param))->sysmat, tv, &tv);
	if (tv.z >= 0)
		conic_projection(
			&tv,
			originsystem(&tp),
			&((warehouse*)(param))->eye,
			&vert->prime);
	else
		vert->prime = ((warehouse*)(param))->eye;
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
