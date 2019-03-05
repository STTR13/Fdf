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

#include "geometry.h"

matrix			*I(matrix *ret)
{
	*ret[0][0] = 1;
	*ret[0][1] = 0;
	*ret[0][2] = 0;
	*ret[1][0] = 0;
	*ret[1][1] = 1;
	*ret[1][2] = 0;
	*ret[2][0] = 0;
	*ret[2][1] = 0;
	*ret[2][2] = 1;
	return (ret);
}

matrix			*rot(ve rot_axis, double angle, matrix *ret)
{
	ve		ura;

	unit(rot_axis, &ura);
	*ret[0][0] = cos(angle) + pow(ura.x, 2) * (1 - cos(angle));
	*ret[0][1] = ura.x * ura.y * (1 - cos(angle)) - ura.z * sin(angle);
	*ret[0][2] = ura.x * ura.z * (1 - cos(angle)) + ura.y * sin(angle);
	*ret[1][0] = ura.y * ura.x * (1 - cos(angle)) + ura.z * sin(angle);
	*ret[1][1] = cos(angle) + pow(ura.y, 2) * (1 - cos(angle));
	*ret[1][2] = ura.y * ura.z * (1 - cos(angle)) - ura.x * sin(angle);
	*ret[2][0] = ura.z * ura.x * (1 - cos(angle)) - ura.y * sin(angle);
	*ret[2][1] = ura.z * ura.y * (1 - cos(angle)) + ura.x * sin(angle);
	*ret[2][2] = cos(angle) + pow(ura.z, 2) * (1 - cos(angle));
	return (ret);
}
