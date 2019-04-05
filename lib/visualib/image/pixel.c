/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:57:19 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 11:57:20 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

bool		set_pxl_img(window *w, int x, int y, int color)
{
	char			*img_ptr;
	unsigned int	nc;
	char			*nc_ptr;
	int				i;

	if (x < 0 || y < 0 || x > w->width || y > w->height)
		return (false);
	img_ptr = w->img->data;
	img_ptr += y * w->img->size_line + w->img->bytes_per_pixel * x;
	nc = mlx_get_color_value(w->mlx_ptr, color);
	nc_ptr = (char *)&nc;
	i = w->img->bytes_per_pixel;
	while (i--)
		img_ptr[i] = nc_ptr[sizeof(unsigned int) - w->img->bytes_per_pixel + i];
	return (true);
}

static int	abs_s(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

/*
** coord x of A = coord[0][0]
** coord y of A = coord[0][1]
** coord x of B = coord[1][0]
** coord y of B = coord[1][1]
** color on A = color[0]
** color on B = color[1]
*/
bool		draw_line_img(window *w, int coord[2][2]/*, int color[2]*/)
{
	int a, b, x;

	if (coord[0][0] < 0 || coord[0][1] < 0 ||
		coord[0][0] > w->width || coord[0][1] > w->height ||
		coord[1][0] < 0 || coord[1][1] < 0 ||
		coord[1][0] > w->width || coord[1][1] > w->height)
		return (false);
	if (abs_s(coord[0][0] - coord[1][0]) > abs_s(coord[0][1] - coord[1][1]))
	{
		if (coord[0][0] < coord[1][0])
		{
			a = 0;
			b = 1;
		}
		else
		{
			a = 1;
			b = 0;
		}
		x = coord[a][0] - 1;
		while (++x <= coord[b][0])
			set_pxl_img(w, x, coord[a][1] +
				((coord[b][1] - coord[a][1]) * (x - coord[a][0]))
				/ (coord[b][0] - coord[a][0]), 255);
	}
	else
	{
		if (coord[0][1] < coord[1][1])
		{
			a = 0;
			b = 1;
		}
		else
		{
			a = 1;
			b = 0;
		}
		x = coord[a][1] - 1;
		while (++x <= coord[b][0])
			set_pxl_img(w, coord[a][1] +
				((coord[b][1] - coord[a][1]) * (x - coord[a][0]))
				/ (coord[b][0] - coord[a][0]), x, 255);
	}
	return(0);
}
