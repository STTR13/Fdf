/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:10:07 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 11:10:08 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_ve			*dot_mv(t_matrix *m, t_ve v, t_ve *ret)
{
	ret->x = m->ai * v.x + m->aj * v.y + m->ak * v.z;
	ret->y = m->bi * v.x + m->bj * v.y + m->bk * v.z;
	ret->z = m->ci * v.x + m->cj * v.y + m->ck * v.z;
	return (ret);
}

t_matrix		*scal_m(t_matrix *m, double s, t_matrix *ret)
{
	ret->ai = m->ai * s;
	ret->aj = m->aj * s;
	ret->ak = m->ak * s;
	ret->bi = m->bi * s;
	ret->bj = m->bj * s;
	ret->bk = m->bk * s;
	ret->ci = m->ci * s;
	ret->cj = m->cj * s;
	ret->ck = m->ck * s;
	return (ret);
}
