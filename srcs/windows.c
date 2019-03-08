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

void	window_init(t_wlist *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WWIDTH, WHEIGHT, "FDF");
	mlx_hook(window->win_ptr, 2, (1L << 0), deal_key, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_key, window);
	mlx_hook(window->win_ptr, 6, (1L << 13), mouse_move, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), windowclose, window);
	mlx_loop(window->mlx_ptr);
}
