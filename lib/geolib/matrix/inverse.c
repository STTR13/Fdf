/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:47:18 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 10:47:19 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

/*
** (m != ret) need to be true
*/

t_matrix		*adj(t_matrix *m, t_matrix *ret)
{
	ret->ai = m->bj * m->ck - m->bk * m->cj;
	ret->aj = -(m->aj * m->ck - m->ak * m->cj);
	ret->ak = m->aj * m->bk - m->ak * m->bj;
	ret->bi = -(m->bi * m->ck - m->bk * m->ci);
	ret->bj = m->ai * m->ck - m->ak * m->ci;
	ret->bk = -(m->ai * m->bk - m->ak * m->bi);
	ret->ci = m->bi * m->cj - m->bj * m->ci;
	ret->cj = -(m->ai * m->cj - m->aj * m->ci);
	ret->ck = m->ai * m->bj - m->aj * m->bi;
	return (ret);
}

double			det(t_matrix *m)
{
	t_matrix a;

	adj(m, &a);
	return (
		a.ai * m->ai
		+ a.aj * m->bi
		+ a.ak * m->ci);
}

/*
** (m != ret) need to be true
*/

t_matrix		*inv(t_matrix *m, t_matrix *ret)
{
	t_matrix	a;
	double		det;

	adj(m, &a);
	det = a.ai * m->ai
		+ a.aj * m->bi
		+ a.ak * m->ci;
	if (det == 0)
		identity(ret);
	else
		scal_m(&a, 1 / det, ret);
	return (ret);
}
