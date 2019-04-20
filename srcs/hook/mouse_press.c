/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_press.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:56:23 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:56:24 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				mouse_press(int key, int x, int y, void *wh)
{
	(void)wh;
	(void)x;
	(void)y;
	if (key == BUT1_KEY)
		ft_putstr("Left Button");
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
