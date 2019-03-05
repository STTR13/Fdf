/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   values.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 09:42:09 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 09:42:10 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

matrix			I(void)
{
	matrix r;

	r[0][0] = 1;
	r[0][1] = 0;
	r[0][2] = 0;
	r[1][0] = 0;
	r[1][1] = 1;
	r[1][2] = 0;
	r[2][0] = 0;
	r[2][1] = 0;
	r[2][2] = 1;
	return (r);
}

matrix			rot(ve rot_axis, double angle)
{
	matrix	m;
	ve		ura;

	ura = unit(rot_axis);
	m[0][0] = cos(angle) + pow(ura->x, 2) * (1 - cos(angle));
	m[0][1] = ura->x * ura->y * (1 - cos(angle)) - ura->z * sin(angle);
	m[0][2] = ura->x * ura->z * (1 - cos(angle)) + ura->y * sin(angle);
	m[1][0] = ura->y * ura->x * (1 - cos(angle)) + ura->z * sin(angle);
	m[1][1] = cos(angle) + pow(ura->y, 2) * (1 - cos(angle));
	m[1][2] = ura->y * ura->z * (1 - cos(angle)) - ura->x * sin(angle);
	m[2][0] = ura->z * ura->x * (1 - cos(angle)) - ura->y * sin(angle);
	m[2][1] = ura->z * ura->y * (1 - cos(angle)) + ura->x * sin(angle);
	m[2][2] = cos(angle) + pow(ura->z, 2) * (1 - cos(angle));
	return (m);
}
