/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:24:03 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 16:24:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				mouse_key(int key, int x, int y, void *window)
{
	(void)window;
	(void)x;
	(void)y;
	if (key == BUT1_KEY)
		mouse_draw_line(window, x, y);
	else if (key == BUT2_KEY)
		ft_putstr("Right Button");
	else if (key == BUT3_KEY)
		ft_putstr("Middle Button");
	else if (key == SCROLLUP_KEY)
		ft_putstr("Scroll Up");
	else if (key == SCROLLDOWN_KEY)
		ft_putstr("Scroll Down");
	return (0);
}

int				mouse_move(int x, int y, void *window)
{
	matrix	m;

	if (x - ((warehouse*)(window))->mouse_last_pos[0] > 300 ||
		y - ((warehouse*)(window))->mouse_last_pos[1] > 300)
	{
		((warehouse*)(window))->mouse_last_pos[0] = x;
		((warehouse*)(window))->mouse_last_pos[1] = y;
		return (0);
	}
	ft_putendl("Mouse_move");
	ft_putnbr(x);
	ft_putendl("");
	ft_putnbr(y);
	ft_putendl("");
	rot(&((warehouse*)(window))->p.l, ((((warehouse*)(window))->mouse_last_pos[0] - x) / 700.00), &m);
	rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	rot(&((warehouse*)(window))->p.m, ((((warehouse*)(window))->mouse_last_pos[1] - y) / 700.00), &m);
	rot_p(&m, &((warehouse*)(window))->p.p, &((warehouse*)(window))->p);
	((warehouse*)(window))->mouse_last_pos[0] = x;
	((warehouse*)(window))->mouse_last_pos[1] = y;
	refresh_win((warehouse*)window);
	return (0);
}
