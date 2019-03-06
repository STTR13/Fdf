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

bool		set_pxl(image *img, int x, int y, int color)
{
	char			*img_ptr;
	unsigned int	nc;
	char			*nc_ptr;
	int				i;

	if (x < 0 || y < 0 || x > img->width || y > img->height)
		return (false);
	img_ptr = img->data;
	img_ptr += y * img->size_line + img->bytes_per_pixel * x;
	nc = mlx_get_color_value(img->mlx_ptr, color);
	nc_ptr = (char *)&nc;
	i = img->bytes_per_pixel;
	while (i--)
		img_ptr[i] = nc_ptr[sizeof(unsigned int) - img->bytes_per_pixel + i];
	return (true);
}
