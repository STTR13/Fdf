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

#include <stdio.h> //(t)
#include "../../libft/includes/libft.h" //(t)

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

	printf("system_lmn_matrix start\n");
	m.ai = plan->l.x;
	m.aj = plan->l.y;
	m.ak = plan->l.z;
	m.bi = plan->m.x;
	m.bj = plan->m.y;
	m.bk = plan->m.z;
	m.ci = plan->n.x;
	m.cj = plan->n.y;
	m.ck = plan->n.z;
	//	printf("system_lmn_matrix end {{%f, %f, %f}{%f, %f ,%f}{%f, %f ,%f}}\n", m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);
	//printf("system_lmn_matrix end %p  \n",&m);

	inv(&m, ret);
	//printf("system_lmn_matrix end {{%f, %f, %f}{%f, %f ,%f}{%f, %f ,%f}}\n", m[0][0], m[0][1], m[0][2], m[1][0], m[1][1], m[1][2], m[2][0], m[2][1], m[2][2]);

	//write(1, "inv done\n", 9);
	return (ret);
}
