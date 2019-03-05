/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 19:40:28 by staeter           #+#    #+#             */
/*   Updated: 2019/03/04 19:40:29 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../geometry.h"

double 			norm(ve v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

ve				unit(ve v)
{
	double	norm;
	ve		rv;

	norm = norm(v);
	rv.x = v.x / norm;
	rv.y = v.y / norm;
	rv.z = v.z / norm;
	return (rv);
}
