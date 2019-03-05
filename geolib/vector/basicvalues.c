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

#include "../geometry.h"

ve				nullvector(void)
{
	ve r;

	r.x = 0;
	r.y = 0;
	r.z = 0;
	return (r);
}

ve				i(void)
{
	ve r;

	r.x = 1;
	r.y = 0;
	r.z = 0;
	return (r);
}

ve				j(void)
{
	ve r;

	r.x = 0;
	r.y = 1;
	r.z = 0;
	return (r);
}

ve				k(void)
{
	ve r;

	r.x = 0;
	r.y = 0;
	r.z = 1;
	return (r);
}
