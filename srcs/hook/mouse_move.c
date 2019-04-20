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

int				mouse_move(int x, int y, void *wh)
{
	t_matrix	m;

	CGGetLastMouseDelta(&x, &y);
	rot(&((t_warehouse*)(wh))->p.l, x / 700.00, &m);
	rot_p(&m, &((t_warehouse*)(wh))->p.p, &((t_warehouse*)(wh))->p);
	rot(&((t_warehouse*)(wh))->p.m, y / 700.00, &m);
	rot_p(&m, &((t_warehouse*)(wh))->p.p, &((t_warehouse*)(wh))->p);
	return (0);
}
