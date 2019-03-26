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
	key_move(key, (t_wlist *)window);
	key_zoom(key, (t_wlist *)window);
	change_view(key, (t_wlist *)window);
	z_valuechange(key, (t_wlist *)window);
	return (0);
}

void	key_move(int key, t_wlist *window)
{
	(void)window;
	if (key == W_KEY)
		ft_putchar('W');
	else if (key == A_KEY)
		ft_putchar('A');
	else if (key == S_KEY)
		ft_putchar('S');
	else if (key == D_KEY)
		ft_putchar('D');
	else if (key == Q_KEY)
		ft_putchar('Q');
	else if (key == E_KEY)
		ft_putchar('E');
	else if (key == H_KEY)
		ft_putchar('H');
	else if (key == ESC_KEY)
		windowclose(window);
}

void	key_zoom(int key, t_wlist *window)
{
	(void)window;
	if (key == 78)
		ft_putchar('-');
	else if (key == 69)
		ft_putchar('+');
}

void	change_view(int key, t_wlist *window)
{
	(void)window;
	if (key == 18)
		ft_putchar('1');
	else if (key == 19)
		ft_putchar('2');
	else if (key == 20)
		ft_putchar('3');
}

void	z_valuechange(int key, t_wlist *window)
{
	(void)window;
	if (key == UP_KEY)
		ft_putstr("up arrow");
	else if (key == DOWN_KEY)
		ft_putstr("down arrow");
	else if (key == LEFT_KEY)
		ft_putstr("left key");
	else if (key == RIGHT_KEY)
		ft_putstr("right key");
}
