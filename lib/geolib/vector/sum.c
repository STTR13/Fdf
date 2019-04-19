/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 10:09:49 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 10:09:50 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_ve		*minus(t_ve *a, t_ve *b, t_ve *ret)
{
	ret->x = a->x - b->x;
	ret->y = a->y - b->y;
	ret->z = a->z - b->z;
	return (ret);
}

t_ve		*plus(t_ve *a, t_ve *b, t_ve *ret)
{
	ret->x = a->x + b->x;
	ret->y = a->y + b->y;
	ret->z = a->z + b->z;
	return (ret);
}
