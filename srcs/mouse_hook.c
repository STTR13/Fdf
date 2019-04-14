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

#include <stdio.h> //(t)

int				windowclose(void *window)
{
	(void)window;
	free_all(window);
	exit(0);
	return (0);
}

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
	matrix m;
	ve v;

	ft_putendl("Mouse_move");
	ft_putnbr(x);
	ft_putendl("");
	ft_putnbr(y);
	ft_putendl("");
	rot(&((t_wlist*)(window))->p.l, ((x - ((t_wlist*)(window))->mouse_last_pos[0]) / 1000.00), &m);
	rot_p(&m, &((t_wlist*)(window))->p.p, &((t_wlist*)(window))->p);
	rot(&((t_wlist*)(window))->p.m, ((y - ((t_wlist*)(window))->mouse_last_pos[1]) / 1000.00), &m);
	rot_p(&m, &((t_wlist*)(window))->p.p, &((t_wlist*)(window))->p);
	((t_wlist*)(window))->mouse_last_pos[0] = x;
	((t_wlist*)(window))->mouse_last_pos[1] = y;
	refresh_win((t_wlist*)window);
	printf("refresh_win done\n");
	return (0);
}
