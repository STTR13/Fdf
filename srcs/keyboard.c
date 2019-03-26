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

int key_press_all(int key, void *window)
{
	key_move(key, (t_wlist *)window);
	key_zoom(key, (t_wlist *)window);
	change_view(key, (t_wlist *)window);
	z_valuechange(key, (t_wlist *)window);
	return(0);
}

void	key_move(int key, t_wlist *window)
{
	(void)window;
	if (key == 13)
		ft_putchar('W');
	else if (key == 0)
		ft_putchar('A');
	else if (key == 1)
		ft_putchar('S');
	else if (key == 2)
		ft_putchar('D');
	else if (key == 12)
		ft_putchar('Q');
	else if (key == 14)
		ft_putchar('E');
	else if (key == 53)
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
	if (key == 126)
		ft_putstr("increasing z value");
	else if (key == 125)
		ft_putstr("decreasing z value");
}
