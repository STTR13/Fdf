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

image		*new_img(void *mlx_ptr, int width, int height)
{
	imgage *r;

	if ((img->width = width) < 0 ||
		(img->height = height) < 0 ||
		!(r = (image*)malloc(sizeof(image))) ||
		!(r->img_ptr = mlx_new_image(mlx_ptr, width, height)))
		return (NULL);
	r->mlx_ptr = mlx_ptr;
	r->data = mlx_get_data_addr(r->img_ptr,
		&r->bytes_per_pixel, &r->size_line, &r->edian);
	r->bytes_per_pixel /= 8;
}

void			free_img(image *img)
{
	free(img->img_ptr);
	free(img->data);
	free(img);
	img = NULL;
}
