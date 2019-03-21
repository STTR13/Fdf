/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:21:36 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 11:21:37 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

image		*new_img(window *w)
{
	image *r;

	if (!(r = (image*)malloc(sizeof(image))) ||
		!(r->img_ptr = mlx_new_image(w->mlx_ptr, w->width, w->height)))
		return (NULL);
	r->data = mlx_get_data_addr(r->img_ptr,
		&r->bytes_per_pixel, &r->size_line, &r->edian);
	r->bytes_per_pixel /= 8;
	return (r);
}

void			free_img(window *w)
{
	mlx_destroy_image(w->mlx_ptr, w->img->img_ptr);
	free(w->img);
	(w->img) = NULL;
}
