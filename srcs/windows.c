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
#include <ApplicationServices/ApplicationServices.h>

void		window_init_load(warehouse *wh)
{
	init_warehouse(wh);
	wh->w->hook.param = (void *)wh;
	wh->w->hook.expose = &expose;
	wh->w->hook.key_press = &key_press;
	wh->w->hook.mouse_press = &mouse_press;
	wh->w->hook.close = &windowclose;
	wh->w->hook.mouse_move = &mouse_move;
	wh->w->hook.key_release = &key_release;
	wh->w->hook.loop = &loop_hook;
	loop(wh->w);
}
