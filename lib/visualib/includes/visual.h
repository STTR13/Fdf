/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:08:08 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 19:08:09 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <math.h>
# include <stdlib.h>

# include "mlx.h"

typedef enum {false=0, true=1} bool;

typedef int	(*key[256])(void *param);

typedef struct	s_image
{
	int			width;
	int			height;
	void 		*mlx_ptr;
	void 		*img_ptr;
	char		*data;
	int			bytes_per_pixel;
	int			size_line;
	int			edian; // 0 = litle edian | 1 = big edian
}				image;

typedef struct	s_rgb
{
	unsigned short		r;
	unsigned short		g;
	unsigned short		b;
}				rgb; //(n) rename to t_rgb

/*
** --- Key ---
*/

void			new_key(key *k);

/*
** --- Image ---
*/

image			*new_img(void *mlx_ptr, int width, int height);
void			free_img(image *img);

bool			set_pxl(image *img, int x, int y, int color);

/*
** --- RedGreenBlue ---
*/

int				get_color(rgb rgb_color, int bytes_per_pixel);

rgb				shadowed(double angle);

#endif
