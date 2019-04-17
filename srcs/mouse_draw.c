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
	int color[2];

	coord[0][0] = ((warehouse*)(window))->mouse_last_pos[0];
	coord[0][1] = ((warehouse*)(window))->mouse_last_pos[1];
	coord[1][0] = x;
	coord[1][1] = y;
	((warehouse*)(window))->mouse_last_pos[0] = x;
	((warehouse*)(window))->mouse_last_pos[1] = y;
	color[0] = (240 << 16) | (59 << 8) | 59;
	color[1] = (240 << 16) | (137 << 8) | 68;
	draw_line_img(((warehouse*)(window))->w, coord, color);
}
