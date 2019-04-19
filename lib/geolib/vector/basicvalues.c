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

t_ve				*nullvector(t_ve *ret)
{
	ret->x = 0;
	ret->y = 0;
	ret->z = 0;
	return (ret);
}

t_ve				*i(t_ve *ret)
{
	ret->x = 1;
	ret->y = 0;
	ret->z = 0;
	return (ret);
}

t_ve				*j(t_ve *ret)
{
	ret->x = 0;
	ret->y = 1;
	ret->z = 0;
	return (ret);
}

t_ve				*k(t_ve *ret)
{
	ret->x = 0;
	ret->y = 0;
	ret->z = 1;
	return (ret);
}

t_ve				*set_ve(double z, double x, double y, t_ve *ret)
{
	ret->x = x;
	ret->y = y;
	ret->z = z;
	return (ret);
}
