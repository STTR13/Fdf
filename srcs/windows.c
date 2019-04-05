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

int	expose(void *window)
{
/*	printf("expose\n");
	if (!(((t_wlist*)(window))->dl = organise(((t_wlist*)(window))->v)))
		return (1);
	draw(((t_wlist*)(window))->w, ((t_wlist*)(window))->dl, 1000, 1700, 255);*/
	return (0);
}

void	window_init_load(t_wlist *window)
{
	window->w = new_window("FDF", 1000, 1000);
	window->w->hook.expose = &expose;
	window->w->hook.param = (void *)window;
	window->w->hook.key_release = &key_press_all;
	window->w->hook.mouse_press = &mouse_key;
	window->w->hook.close = &windowclose;
	//window->w->hook.mouse_move = &mouse_move;
	loop(window->w);
	/*window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WWIDTH, WHEIGHT, "FDF");
	int i = 0;
	int x = 0;
	int j = 10;
	while (i <= window->file->lines * window->file->linelen)
	{
		while (x < window->file->linelen)
		{
			if (window->v->color == NULL)
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->v->v.x * 2, window->v->v.y * 2, 255);
			else
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->v->v.x * 2, window->v->v.y * 2, ft_hexaconverter(window->v->color));
			x++;
			i++;
			window->v++;
		}
		j += 1;
		x = 0;
		i++;
	}
	mlx_hook(window->win_ptr, 2, (1L << 0), deal_key, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_key, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), windowclose, window);
	mlx_loop(window->mlx_ptr);*/
}
