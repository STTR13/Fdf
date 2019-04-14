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

#include <stdio.h> //(t)
#include "../../libft/includes/libft.h" //(t)

/*
** (m != ret) need to be true
*/
matrix			*adj(matrix *m, matrix *ret)
{
	ret->ai = m->bj * m->ck - m->bk * m->cj;
	ret->aj = - (m->aj * m->ck - m->ak * m->cj);
	ret->ak = m->aj * m->bk - m->ak * m->bj;
	ret->bi = - (m->bi * m->ck - m->bk * m->ci);
	ret->bj = m->ai * m->ck - m->ak * m->ci;
	ret->bk = - (m->ai * m->bk - m->ak * m->bi);
	ret->ci = m->bi * m->cj - m->bj * m->ci;
	ret->cj = - (m->ai * m->cj - m->aj * m->ci);
	ret->ck = m->ai * m->bj - m->aj * m->bi;
	return (ret);
}

double			det(matrix *m)
{
	matrix a;

	adj(m, &a);
	return (
		a.ai * m->ai
		+ a.aj * m->bi
		+ a.ak * m->ci
	);
}

/*
** (m != ret) need to be true
*/
matrix			*inv(matrix *m, matrix *ret)
{
	matrix	a;
	double	det;

	//printf("inv start\n");
	adj(m, &a);
	//printf("system_lmn_matrix end {{%f, %f, %f}, {%f, %f ,%f}, {%f, %f ,%f}}\n", a->ai, a->aj, a->ak, a->bi, a->bj, a->bk, a->ci, a->cj, a->ck);
	det = a.ai * m->ai
		+ a.aj * m->bi
		+ a.ak * m->ci;
	//printf("inv end %p \n",ret);
	if (det == 0)
		I(ret);
	else
		scal_m(&a, 1 / det, ret);
	//ft_putstr("I or scal_m done\n");
	//printf("system_lmn_matrix end   after %p  \n",m);

	return (ret);
}
