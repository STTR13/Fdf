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

static double		abs_s(double nb)
{
	if (nb < 0)
		return (-1 * nb);
	return (nb);
}

ve				*conic_projection(ve *point, pl *p, ve *eye, ve *ret)
{
	double	a, b;
	ve		tv;

	a = dot_vv(minus(point, &p->p, &tv), &p->n);
	b = dot_vv(minus(eye, &p->p, &tv), &p->n);
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
		return (nullvector(ret));
	a = abs_s(a);
	b = abs_s(b);
	plus(point, scal_v(minus(point, eye, &tv), a / (a + b), &tv), ret);
	return (ret);
}
