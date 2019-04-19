/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   booleans.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:15:54 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 10:15:55 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_bool			isnullvector(t_ve *v)
{
	if (v->x == 0 && v->y == 0 && v->z == 0)
		return (true);
	return (false);
}

t_bool			equal_v(t_ve *a, t_ve *b)
{
	if (a->x == b->x && a->y == b->y && a->z == b->z)
		return (true);
	return (false);
}

t_bool			equal_x_y(t_ve *a, t_ve *b)
{
	if (a->x == b->x && a->y == b->y)
		return (true);
	return (false);
}
