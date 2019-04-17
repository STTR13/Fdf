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
#include <stdio.h> //(t)

bool		set_pxl_img(window *w, int x, int y, int color)
{
	char			*img_ptr;
	unsigned int	nc;
	char			*nc_ptr;
	int				i;

	if (!w->img || x < 0 || y < 0 || x > w->width || y > w->height)
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
		return (-1 * nb);
	return (nb);
}

static int	get_light(int start, int end, double percentage)
{
	return ((1 - percentage) * start + percentage * end);
}

/*
** coord x of A = coord[0][0]
** coord y of A = coord[0][1]
** coord x of B = coord[1][0]
** coord y of B = coord[1][1]
** color on A = color[0]
** color on B = color[1]
*/
bool		draw_line_img(window *w, int coord[2][2], int color[2])
{
	int a, runaxis, i, d[2], c;
	double pxl[2];

	if (!w->img ||
		((coord[0][0] < 0 || coord[0][1] < 0
			|| coord[0][0] > w->width || coord[0][1] > w->height)
		&&
		(coord[1][0] < 0 || coord[1][1] < 0
			|| coord[1][0] > w->width || coord[1][1] > w->height)))
		return (false);
	d[0] = abs_s(coord[0][0] - coord[1][0]);
	d[1] = abs_s(coord[0][1] - coord[1][1]);
	if (d[0] >= d[1])
		runaxis = 0;
	else
		runaxis = 1;
	a = coord[0][runaxis] > coord[1][runaxis];
	d[0] = coord[!a][0] - coord[a][0];
	d[1] = coord[!a][1] - coord[a][1];
	c = get_light(color[a], color[!a],
		(double)(coord[a][runaxis]) /
		(coord[a][runaxis] + coord[!a][runaxis]));
	i = 0;
	while (i <= d[runaxis])
	{
		pxl[0] = i + coord[a][runaxis];
		pxl[1] = (d[runaxis] ? ((double)(d[!runaxis]) / d[runaxis]) : 0) * i
						+ (double)coord[a][!runaxis];
		set_pxl_img(w, (int)pxl[runaxis], (int)pxl[!runaxis], c);
		i++;
	}
	return (true);
}
