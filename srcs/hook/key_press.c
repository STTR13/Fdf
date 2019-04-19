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

static void	key_press_sub1(int key, warehouse *window)
{
	if (key == W_KEY)
		plus(&window->p.p, &window->p.n, &window->p.p);
	if (key == S_KEY)
		minus(&window->p.p, &window->p.n, &window->p.p);
	if (key == A_KEY)
		minus(&window->p.p, &window->p.m, &window->p.p);
	if (key == D_KEY)
		plus(&window->p.p, &window->p.m, &window->p.p);
	if (key == R_KEY)
		plus(&window->p.p, &window->p.l, &window->p.p);
	if (key == F_KEY)
		minus(&window->p.p, &window->p.l, &window->p.p);
}

static void	key_press_sub2(int key, warehouse *window)
{
	matrix m;

	if (key == V_KEY)
		((warehouse*)(window))->mode = !((warehouse*)(window))->mode;
	if (key == M_KEY)
		((warehouse*)(window))->mouse = !((warehouse*)(window))->mouse;
	if (key == E_KEY)
	{
		rot(&((warehouse*)(window))->p.n, 0.1, &m);
		rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	}
	if (key == Q_KEY)
	{
		rot(&((warehouse*)(window))->p.n, -0.1, &m);
		rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	}
	if (key == ESC_KEY)
		windowclose(window);
}

int			key_press(int key, void *window)
{
	key_press_sub1(key, (warehouse *)window);
	key_press_sub2(key, (warehouse *)window);
	refresh_win((warehouse*)(window));
	return (0);
}
