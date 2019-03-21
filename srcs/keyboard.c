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

void key_move(int key, t_wlist *window)
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
		ft_putchar('A');
	else if (key == 14)
		ft_putchar('E');
}

void key_zoom(int key, t_wlist *window)
{
	(void)window;
	if (key == 78)
		ft_putchar('-');
	else if (key == 69)
		ft_putchar('+');
}
