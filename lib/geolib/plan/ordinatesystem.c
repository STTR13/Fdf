/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordinatesystem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:10:25 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 18:10:26 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

void	set_lm(pl *p, bool toward_origin)
{
	ve t[2];

	p->m = *unit(
		*cross(
			(*p).n,
			*scal_v(
				*k(&t[0]),
				(toward_origin) ? 1 : -1,
				&t[1]
			),
			&t[0]
		),
		&t[1]
	);
	p->l = *unit(
		*cross(
			(*p).m,
			(*p).n,
			&t[0]
		),
		&t[1]
	);
}

matrix	*system_lmn_matrix(pl plan, matrix *ret)
{
	matrix m;

	m[0][0] = plan.l.x;
	m[0][1] = plan.l.y;
	m[0][2] = plan.l.z;
	m[1][0] = plan.m.x;
	m[1][1] = plan.m.y;
	m[1][2] = plan.m.z;
	m[2][0] = plan.n.x;
	m[2][1] = plan.n.y;
	m[2][2] = plan.n.z;
	return (inv(m, ret));
}
