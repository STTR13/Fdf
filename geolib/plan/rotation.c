/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:34:57 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 18:34:59 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

ve				rot_pl(ve rot_axis, ve rot_center, pl plan, double angle)
{
	ve p_prime;

	plan->l = rot_ve(rot_axis, plan->l, angle);
	plan->m = rot_ve(rot_axis, plan->m, angle);
	plan->n = rot_ve(rot_axis, plan->n, angle);
	plan->p = plus(
		rot_center,
		rot_ve(rot_axis, minus(p->p, rot_center), angle)
	);
	return (plan);
}
