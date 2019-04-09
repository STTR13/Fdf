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
#include <stdio.h> //(t)

int		expose(void *window)
{
	printf("expose\n");
	draw_model(((t_wlist*)(window))->w, ((t_wlist*)(window))->e);
	put_img(((t_wlist*)(window))->w);
	return (0);
}

// window->w->hook.mouse_move = &mouse_move;

void	window_init_load(t_wlist *window)
{
	window->w = new_window("FDF", 1000, 1000);
	window->w->hook.expose = &expose;
	window->w->hook.param = (void *)window;
	window->w->hook.key_release = &key_press_all;
	window->w->hook.mouse_press = &mouse_key;
	window->w->hook.close = &windowclose;
	loop(window->w);
}
