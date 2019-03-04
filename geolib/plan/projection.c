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

#include "../geometry.h"

ve				ortho_projection(ve point, pl p)
{
	double	t;

	t = dot(p->n, minus(p->p, point)) / dot(p->n, p->n);
	return((t >= 0) ? nullvector() : plus(point, scal(p->n, t)));
}

ve				conic_projection(ve point, pl p, ve eye)
{
	double	t;
	ve		nl;

	nl = unit(minus(point, eye));
	t = dot(p->n, minus(p->p, point)) / dot(p->n, nl);
	return((t >= 0) ? nullvector() : plus(point, scal(nl, t)));
}
