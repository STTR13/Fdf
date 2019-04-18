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
	//mlx_mouse_get_pos(???mlx_win_list_t *win???,
	//	((warehouse*)window)->mouse_last_pos[0],
	//	((warehouse*)window)->mouse_last_pos[1]);
	refresh_win((warehouse*)window);
	return (0);
}

void		window_init_load(warehouse *wh)
{
	init_warehouse(wh);
	wh->w->hook.expose = &expose;
	wh->w->hook.param = (void *)wh;
	wh->w->hook.key_press = &key_press_all;
	wh->w->hook.mouse_press = &mouse_key;
	wh->w->hook.close = &windowclose;
	wh->w->hook.mouse_move = &mouse_move;
	loop(wh->w);
}
