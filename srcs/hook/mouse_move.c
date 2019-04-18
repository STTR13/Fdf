/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:56:58 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:57:00 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
