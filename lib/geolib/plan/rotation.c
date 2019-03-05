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

#include "geometry.h"

pl				rot_p(matrix rot_matrix, ve rot_center, pl plan)
{
	ve t[2];

	plan.l = *dot_mv(rot_matrix, plan.l, &t[0]);
	plan.m = *dot_mv(rot_matrix, plan.m, &t[0]);
	plan.n = *dot_mv(rot_matrix, plan.n, &t[0]);
	plan.p = *plus(
		rot_center,
		*dot_mv(
			rot_matrix,
			*minus(plan.p, rot_center, &t[0]),
			&t[1]
		),
		&t[0]
	);
	return (plan);
}
