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

void	window_init_load(t_wlist *window)
{
	window->test = new_window("FDF", 1000, 1000);
	window->test->hook.param = &window;
	window->test->hook.key_release = &key_press_all;
	window->test->hook.mouse_press = &mouse_key;
	window->test->hook.close = &windowclose;
	window->test->hook.mouse_move = &mouse_move;
	loop(window->test);
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
