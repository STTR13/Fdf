/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 09:28:25 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/21 09:28:27 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_press_all(int key, void *window)
{
	key_move(key, (warehouse *)window);
	key_zoom(key, (warehouse *)window);
	change_view(key, (warehouse *)window);
	return (0);
}

void	key_move2(int key, warehouse *window)
{
	matrix m;

	if (key == V_KEY)
		((warehouse*)(window))->mode = !((warehouse*)(window))->mode;
	else if (key == E_KEY)
	{
		rot(&((warehouse*)(window))->p.n, 0.1, &m);
		rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	}
	else if (key == Q_KEY)
	{
		rot(&((warehouse*)(window))->p.n, -0.1, &m);
		rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	}
	else if (key == ESC_KEY)
		windowclose(window);
	refresh_win((warehouse*)(window));
}

void	key_move(int key, warehouse *window)
{
	if (key == W_KEY)
		minus(&window->p.p, &window->p.n, &window->p.p);
	else if (key == S_KEY)
		plus(&window->p.p, &window->p.n, &window->p.p);
	else if (key == A_KEY)
		plus(&window->p.p, &window->p.m, &window->p.p);
	else if (key == D_KEY)
		minus(&window->p.p, &window->p.m, &window->p.p);
	else if (key == R_KEY)
		plus(&window->p.p, &window->p.l, &window->p.p);
	else if (key == F_KEY)
		minus(&window->p.p, &window->p.l, &window->p.p);
	else
		key_move2(key, window);
	refresh_win((warehouse*)(window));
}

void	key_zoom(int key, warehouse *window)
{
	(void)window;
	if (key == 78)
		ft_putchar('-');
	else if (key == 69)
		ft_putchar('+');
}

void	change_view(int key, warehouse *window)
{
	(void)window;
	if (key == 18)
		ft_putchar('1');
	else if (key == 19)
		ft_putchar('2');
	else if (key == 20)
		ft_putchar('3');
}
