/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basicvalues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:42:59 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 16:43:01 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

ve				*nullvector(ve *ret)
{
	ret->x = 0;
	ret->y = 0;
	ret->z = 0;
	return (ret);
}

ve				*i(ve *ret)
{
	ret->x = 1;
	ret->y = 0;
	ret->z = 0;
	return (ret);
}

ve				*j(ve *ret)
{
	ret->x = 0;
	ret->y = 1;
	ret->z = 0;
	return (ret);
}

ve				*k(ve *ret)
{
	ret->x = 0;
	ret->y = 0;
	ret->z = 1;
	return (ret);
}

ve				*set_ve(double z, double x, double y, ve *ret)
{
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
