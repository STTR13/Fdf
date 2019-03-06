/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:30:07 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 14:30:08 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

void			draw(image *img, drawing_list *dl,
					double modeled_width, double modeled_height, rgb color)
{
	int	i, count;
	double x, x_prop, y_prop, m, p;
	drawing_list	*run;

	x_prop = modeled_width / (double)(img->width);
	y_prop = modeled_height / (double)(img->height);
	x = 0;
	while (x < modeled_width)
	{
		run = dl;
		while (run && x > run->vert->v.x)
		{
			i = -1;
			count = 0;
			while (++i < 4)
			{
				run->vert->done = true;
				if (!run->vert->next[i] || run->vert->next[i]->done)
				{
					count++;
					continue ;
				}
				m = (run->vert->next[i]->v.y - run->vert->v.y)
					/ (run->vert->next[i]->v.x - run->vert->v.x);
				p = run->vert->v.y - m * run->vert->v.x;
				set_pxl(img, (int)(x / x_prop), (int)((m * x + p) / y_prop),
					get_color(color, img->bytes_per_pixel));
			}
			if (count == 4 && run == dl)
				dl = dl->next;
			run = run->next;
		}
		x += x_prop;
	}
	reset_vertex(dl->vert);
}
