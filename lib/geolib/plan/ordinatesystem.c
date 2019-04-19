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
		cross(
			&(*p).n,
			scal_v(
				k(&t[0]),
				(toward_origin) ? 1 : -1,
				&t[1]
			),
			&t[0]
		),
		&t[1]
	);
	p->l = *unit(
		cross(
			&(*p).m,
			&(*p).n,
			&t[0]
		),
		&t[1]
	);
}

matrix	*system_lmn_matrix(pl *plan, matrix *ret)
{
	matrix m;

	m.ai = plan->l.x;
	m.bi = plan->l.y;
	m.ci = plan->l.z;
	m.aj = plan->m.x;
	m.bj = plan->m.y;
	m.cj = plan->m.z;
	m.ak = plan->n.x;
	m.bk = plan->n.y;
	m.ck = plan->n.z;
	return (inv(&m, ret));
}
