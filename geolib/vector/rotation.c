/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:42:01 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 16:42:03 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

ve	rot_ve(ve rot_axis, ve v, double angle)
{
	ve	vt[5];

	vt[4] = unit(rotation_axis);
	vt[1]->x = cos(angle) + pow(vt[4]->x, 2) * (1 - cos(angle));
	vt[1]->y = vt[4]->x * vt[4]->y * (1 - cos(angle)) - vt[4]->z * sin(angle);
	vt[1]->z = vt[4]->x * vt[4]->z * (1 - cos(angle)) + vt[4]->y * sin(angle);
	vt[2]->x = vt[4]->y * vt[4]->x * (1 - cos(angle)) + vt[4]->z * sin(angle);
	vt[2]->y = cos(angle) + pow(vt[4]->y, 2) * (1 - cos(angle));
	vt[2]->z = vt[4]->y * vt[4]->z * (1 - cos(angle)) - vt[4]->x * sin(angle);
	vt[3]->x = vt[4]->z * vt[4]->x * (1 - cos(angle)) - vt[4]->y * sin(angle);
	vt[3]->y = vt[4]->z * vt[4]->y * (1 - cos(angle)) + vt[4]->x * sin(angle);
	vt[3]->z = cos(angle) + pow(vt[4]->z, 2) * (1 - cos(angle));
	vt[0]->x = dot(vt[1], v);
	vt[0]->y = dot(vt[2], v);
	vt[0]->z = dot(vt[3], v);
	return (vt[0]);
}
