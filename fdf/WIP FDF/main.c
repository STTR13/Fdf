/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:30:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 16:25:18 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void window_init(twin_list *window)
{
	window->title = "fdf";
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 500, 500, window->title);
	mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_mouse_hook(window->win_ptr, mouse_key, window);
	mlx_loop(window->mlx_ptr);
}

int main()
{
	twin_list window;
	window_init(&window);
}
