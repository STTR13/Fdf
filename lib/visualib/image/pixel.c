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

	if (x < 0 || y < 0 || x > w->img->width || y > w->img->height)
		return (false);
	img_ptr = w->img->data;
	img_ptr += y * w->img->size_line + w->img->bytes_per_pixel * x;
	nc = mlx_get_color_value(w->img->mlx_ptr, color);
	nc_ptr = (char *)&nc;
	i = w->img->bytes_per_pixel;
	while (i--)
		img_ptr[i] = nc_ptr[sizeof(unsigned int) - w->img->bytes_per_pixel + i];
	return (true);
}

void		clear_img(window *w)
{

}
