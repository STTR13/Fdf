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

pl				rot_p(m rot_matrix, ve rot_center, pl plan)
{
	plan.l = dot_mv(rot_matrix, plan.l);
	plan.m = dot_mv(rot_matrix, plan.m);
	plan.n = dot_mv(rot_matrix, plan.n);
	plan.p = plus(
		rot_center,
		dot_mv(rot_matrix, minus(plan.p, rot_center))
	);
	return (plan);
}
