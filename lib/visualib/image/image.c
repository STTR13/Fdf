/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 11:21:36 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 11:21:37 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_bool		new_img(t_window *w)
{
	if (!(w->img = (t_image*)malloc(sizeof(t_image))) ||
		!(w->img->img_ptr = mlx_new_image(w->mlx_ptr, w->width, w->height)))
		return (0);
	w->img->data = mlx_get_data_addr(w->img->img_ptr,
		&w->img->bytes_per_pixel, &w->img->size_line, &w->img->edian);
	w->img->bytes_per_pixel /= 8;
	return (1);
}

void		free_img(t_window *w)
{
	mlx_destroy_image(w->mlx_ptr, w->img->img_ptr);
	free(w->img);
	(w->img) = NULL;
}

t_bool		re_img(t_window *w)
{
	if (w->img)
		free_img(w);
	return (new_img(w));
}

t_bool		put_img(t_window *w)
{
	if (!w->img)
		return (false);
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->img_ptr, 0, 0);
	return (true);
}
