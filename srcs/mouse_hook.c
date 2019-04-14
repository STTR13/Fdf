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

int				windowclose(void *window)
{
	(void)window;
	ft_putstr("exiting");
	exit(0);
	return (0);
}

int				mouse_key(int key, int x, int y, void *window)
{
	int coord[2][2];

	(void)window;
	(void)x;
	(void)y;
	if (key == BUT1_KEY)
	{
		ft_putstr("Left Button\n");/*
		//set_pxl_img(((t_wlist*)(window))->w, x, y, 255);
		coord[0][0] = ((t_wlist*)(window))->mouse_last_pos[0];
		coord[0][1] = ((t_wlist*)(window))->mouse_last_pos[1];
		coord[1][0] = x;
		coord[1][1] = y;
		((t_wlist*)(window))->mouse_last_pos[0] = x;
		((t_wlist*)(window))->mouse_last_pos[1] = y;
		draw_line_img(((t_wlist*)(window))->w, coord);*/
		((t_wlist*)(window))->mode = !((t_wlist*)(window))->mode;
		refresh_win((t_wlist*)(window));
	}
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
	rot(k(&v), -(x / 600.00), &m);
	rot_p(&m, &((t_wlist*)(window))->p.p, &((t_wlist*)(window))->p);
	rot(&((t_wlist*)(window))->p.m, -(y / 600.00), &m);
	rot_p(&m, &((t_wlist*)(window))->p.p, &((t_wlist*)(window))->p);
	((t_wlist*)(window))->mouse_last_pos[0] = x;
	((t_wlist*)(window))->mouse_last_pos[1] = y;
	refresh_win((t_wlist*)window);
	printf("refresh_win done\n");
	return (0);
}
