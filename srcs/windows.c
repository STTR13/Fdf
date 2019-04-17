/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:59:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/06 09:59:06 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			windowclose(void *window)
{
	free_all(window);
	exit(0);
	return (0);
}

static int	expose(void *window)
{
	refresh_win((warehouse*)window);
	return (0);
}

void		window_init_load(warehouse *window)
{
	window->w = new_window("FDF", 1000, 1000);
	window->p.n.x = 1;
	window->p.n.y = 1;
	window->p.n.z = -1;
	unit(&window->p.n, &window->p.n);
	window->p.p.x = 0;
	window->p.p.y = 0;
	window->p.p.z = 5;
	set_lm(&window->p, 1);
	window->eye.x = 0;
	window->eye.y = 0;
	window->eye.z = -100;
	window->w->hook.expose = &expose;
	window->w->hook.param = (void *)window;
	window->w->hook.key_press = &key_press_all;
	window->w->hook.mouse_press = &mouse_key;
	window->w->hook.close = &windowclose;
	window->w->hook.mouse_move = &mouse_move;
	loop(window->w);
}
