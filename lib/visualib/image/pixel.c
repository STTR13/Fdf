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

t_bool		set_pxl_img(t_window *w, int x, int y, int color)
{
	char			*img_ptr;
	unsigned int	nc;
	char			*nc_ptr;
	int				i;

	if (!w->img || x < 0 || y < 0 || x >= w->width || y >= w->height)
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

static int	get_light(int color[2], int i, int end, int start)
{
	double percentage;

	percentage = (double)(i - start) / (double)(end - start);
	return ((int)((1 - percentage) * color[0]) + (int)(percentage * color[1]));
}

/*
** cor x of A = cor[0][0]
** cor y of A = cor[0][1]
** cor x of B = cor[1][0]
** cor y of B = cor[1][1]
** color on A = color[0]
** color on B = color[1]
**
** norm clarity:
** v[0] = a
** v[1] = runaxis
** v[2] = i
*/

t_bool		draw_line_img(t_window *w, int cor[2][2], int color[2])
{
	int		v[3];
	int		d[2];
	double	pxl[2];

	if (!w->img || ((cor[0][0] < 0 || cor[0][1] < 0 || cor[0][0] > w->width ||
		cor[0][1] > w->height) && (cor[1][0] < 0 || cor[1][1] < 0 ||
		cor[1][0] > w->width || cor[1][1] > w->height)))
		return (false);
	d[0] = abs_s(cor[0][0] - cor[1][0]);
	d[1] = abs_s(cor[0][1] - cor[1][1]);
	v[1] = (d[0] >= d[1]) ? 0 : 1;
	v[0] = cor[0][v[1]] > cor[1][v[1]];
	d[0] = cor[!v[0]][0] - cor[v[0]][0];
	d[1] = cor[!v[0]][1] - cor[v[0]][1];
	v[2] = 0;
	while (v[2] <= d[v[1]])
	{
		pxl[0] = v[2] + cor[v[0]][v[1]];
		pxl[1] = (d[v[1]] ? ((double)(d[!v[1]]) / d[v[1]]) : 0) * v[2]
						+ (double)cor[v[0]][!v[1]];
		set_pxl_img(w, (int)pxl[v[1]], (int)pxl[!v[1]],
			get_light(color, v[2], cor[v[0]][v[1]], cor[!v[0]][v[1]]));
		v[2]++;
	}
	return (true);
}
