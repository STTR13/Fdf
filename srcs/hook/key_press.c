/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:56:10 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:56:11 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"
#include <ApplicationServices/ApplicationServices.h>

static void	key_press_sub1(int key, t_warehouse *wh)
{
	if (key == W_KEY)
		plus(&wh->p.p, &wh->p.n, &wh->p.p);
	if (key == S_KEY)
		minus(&wh->p.p, &wh->p.n, &wh->p.p);
	if (key == A_KEY)
		minus(&wh->p.p, &wh->p.m, &wh->p.p);
	if (key == D_KEY)
		plus(&wh->p.p, &wh->p.m, &wh->p.p);
	if (key == R_KEY)
		plus(&wh->p.p, &wh->p.l, &wh->p.p);
	if (key == F_KEY)
		minus(&wh->p.p, &wh->p.l, &wh->p.p);
}

static void	key_press_sub2(int key, t_warehouse *wh)
{
	t_matrix m;

	if (key == V_KEY)
		wh->mode = !wh->mode;
	if (key == M_KEY)
		wh->mouse = !wh->mouse;
	if (key == E_KEY)
	{
		rot(&wh->p.n, 0.1, &m);
		rot_p(&m, &wh->p.p, &wh->p);
	}
	if (key == Q_KEY)
	{
		rot(&wh->p.n, -0.1, &m);
		rot_p(&m, &wh->p.p, &wh->p);
	}
	if (key == ESC_KEY)
		windowclose(wh);
	if (key == M_KEY)
		CGDisplayHideCursor(kCGDirectMainDisplay);
}

int			key_press(int key, void *wh)
{
	key_press_sub1(key, (t_warehouse *)wh);
	key_press_sub2(key, (t_warehouse *)wh);
	return (0);
}
