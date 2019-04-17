/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 09:57:51 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/09 09:57:53 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	mouse_draw_line(void *window, int x, int y)
{
	static int coord[2][2];

	coord[0][0] = ((warehouse*)(window))->mouse_last_pos[0];
	coord[0][1] = ((warehouse*)(window))->mouse_last_pos[1];
	coord[1][0] = x;
	coord[1][1] = y;
	((warehouse*)(window))->mouse_last_pos[0] = x;
	((warehouse*)(window))->mouse_last_pos[1] = y;
	draw_line_img(((warehouse*)(window))->w, coord);
}
