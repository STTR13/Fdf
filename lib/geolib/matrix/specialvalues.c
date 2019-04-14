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
	ret->ai = 1;
	ret->aj = 0;
	ret->ak = 0;
	ret->bi = 0;
	ret->bj = 1;
	ret->bk = 0;
	ret->ci = 0;
	ret->cj = 0;
	ret->ck = 1;
	return (ret);
}

matrix			*rot(ve *rot_axis, double angle, matrix *ret)
{
	ve		ura;

	unit(rot_axis, &ura);
	ret->ai = cos(angle) + pow(ura.x, 2) * (1 - cos(angle));
	ret->aj = ura.x * ura.y * (1 - cos(angle)) - ura.z * sin(angle);
	ret->ak = ura.x * ura.z * (1 - cos(angle)) + ura.y * sin(angle);
	ret->bi = ura.y * ura.x * (1 - cos(angle)) + ura.z * sin(angle);
	ret->bj = cos(angle) + pow(ura.y, 2) * (1 - cos(angle));
	ret->bk = ura.y * ura.z * (1 - cos(angle)) - ura.x * sin(angle);
	ret->ci = ura.z * ura.x * (1 - cos(angle)) - ura.y * sin(angle);
	ret->cj = ura.z * ura.y * (1 - cos(angle)) + ura.x * sin(angle);
	ret->ck = cos(angle) + pow(ura.z, 2) * (1 - cos(angle));
	return (ret);
}
