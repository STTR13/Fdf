/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:10:25 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 18:10:26 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

void	set_lm(pl *p, bool toward_origin)
{
	(*p)->m = unit(cross((*p)->n, scal(k(), (toward_origin) ? 1 : -1)));
	(*p)->l = unit(cross((*p)->m, (*p)->n));
}

ve		to_lmn(ve point, pl plan)
{
	ve		vt[5];
	double	det;

	vt[1]->x = plan->m->y * plan->n->z - plan->m->z * plan->n->y;
	vt[1]->y = - (plan->l->y * plan->n->z - plan->l->z * plan->n->y);
	vt[1]->z = plan->l->y * plan->m->z - plan->l->z * plan->m->y;
	vt[2]->x = - (plan->m->x * plan->n->z - plan->m->z * plan->n->x);
	vt[2]->y = plan->l->x * plan->n->z - plan->l->z * plan->n->x;
	vt[2]->z = - (plan->l->x * plan->m->z - plan->l->z * plan->m->x);
	vt[3]->x = plan->m->x * plan->n->y - plan->m->y * plan->n->x;
	vt[3]->y = - (plan->l->x * plan->n->y - plan->l->y * plan->n->x);
	vt[3]->z = plan->l->x * plan->m->y - plan->l->y * plan->m->x;
	det = vt[1]->x * plan->l->x + vt[1]->y * plan->m->x + vt[1]->z * plan->n->x;
	vt[0]->x = dot(vt[1], v) / det;
	vt[0]->y = dot(vt[2], v) / det;
	vt[0]->z = dot(vt[3], v) / det;
	return (vt[0]);
}
