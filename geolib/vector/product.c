/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   product.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:40:35 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 16:40:37 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

ve 						cross(ve a, ve b)
{
	ve	rv;

	rv->x = a->y * b->z - a->z * b->y;
	rv->y = a->z * b->x - a->x * b->z;
	rv->z = a->x * b->y - a->y * b->x;
	return (rv);
}

double 					dot(ve a, ve b)
{
	return (a->x * b->x + a->y * b->y + a->z * b->z);
}

ve						scal(ve v, double s)
{
	v->x = v->y * s;
	v->y = v->z * s;
	v->z = v->x * s;
	return (v);
}
