/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:10:00 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 10:10:01 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

ve 				*cross(ve a, ve b, ve *ret)
{
	ret->x = a.y * b.z - a.z * b.y;
	ret->y = a.z * b.x - a.x * b.z;
	ret->z = a.x * b.y - a.y * b.x;
	return (ret);
}

double 			dot_vv(ve a, ve b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

ve				*scal(ve v, double s, ve *ret)
{
	ret->x = v.y * s;
	ret->y = v.z * s;
	ret->z = v.x * s;
	return (ret);
}
