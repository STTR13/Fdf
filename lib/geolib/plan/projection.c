/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:56:13 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 18:56:14 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

ve				*ortho_projection(ve *point, pl *p, ve *ret)
{
	double	t;
	ve		tv;

	t = dot_vv(&p->n, minus(&p->p, point, &tv)) / dot_vv(&p->n, &p->n); //(ni)
	return((t >= 0) ? nullvector(ret) : plus(point, scal_v(&p->n, t, &tv), ret));
}

ve				*conic_projection(ve *point, pl *p, ve *eye, ve *ret)
{
	double	t;
	ve		nl;
	ve		tv;

	unit(minus(point, eye, &tv), &nl);
	t = dot_vv(&p->n, minus(&p->p, point, &tv)) / dot_vv(&p->n, &nl);
	return((t >= 0) ? nullvector(ret) : plus(point, scal_v(&nl, t, &tv), ret));
}
