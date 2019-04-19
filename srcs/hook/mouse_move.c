/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:56:58 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:57:00 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <ApplicationServices/ApplicationServices.h>

int				mouse_move(int x, int y, void *window)
{
	matrix	m;

	CGGetLastMouseDelta(&x, &y);
	rot(&((warehouse*)(window))->p.l, x / 700.00, &m);
	rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	rot(&((warehouse*)(window))->p.m, y / 700.00, &m);
	rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	refresh_win((warehouse*)window);
	return (0);
}
