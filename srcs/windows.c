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

int		expose(void *window)
{
	originsystem(&((t_wlist*)(window))->p);
	refresh_win((t_wlist*)window);
	return (0);
}

void	window_init_load(t_wlist *window)
{
	window->w = new_window("FDF", 1000, 1000);
	originsystem(&window->p);
	window->eye.x = 0;
	window->eye.y = 0;
	window->eye.z = -10;
	window->eye.z = 0;
	window->w->hook.expose = &expose;
	window->w->hook.param = (void *)window;
	window->w->hook.key_press = &key_press_all;
	window->w->hook.mouse_press = &mouse_key;
	window->w->hook.close = &windowclose;
	window->w->hook.mouse_move = &mouse_move;
	loop(window->w);
}
