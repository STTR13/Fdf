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

int	windowclose(t_wlist *window)
{
	(void)window;
	exit(0);
	return (0);
}

int	deal_key(int key, t_wlist *window)
{
	if (key == 13 || key == 0 || key == 1 || key == 2 || key == 12 || key == 14)
		key_move(key, window);
	else if (key == 18 || key == 19 || key == 20)
		change_view(key, window);
	else if (key == 78 || key == 69)
		key_zoom(key, window);
	else if (key == 4)
		ft_putchar('H');
	else if (key == 53)
		exit(0);
	return (0);
}

int	mouse_key(int key, t_wlist *window)
{
	(void)window;
	if (key == 1)
		ft_putstr("Left Button");
	else if (key == 2)
		ft_putstr("Right Button");
	else if (key == 3)
		ft_putstr("Middle Button");
	else if (key == 4)
		ft_putstr("Scroll Up");
	else if (key == 5)
		ft_putstr("Scroll Down");
	return (0);
}
