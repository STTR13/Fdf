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

#include <stdio.h> //(t)

void			draw(window *w, drawing_list *dl,
					double modeled_width, double modeled_height, int color)
{
	int	i, count;
	double x, x_prop, y_prop, m, p;
	drawing_list	*run;

	reset_vertex(dl->vert);
	x_prop = modeled_width / (double)(w->width);
	y_prop = modeled_height / (double)(w->height);
	printf("draw(%s, dl, %f, %f, %d) : (%d, %d) (%f, %f)\n", w->name, modeled_width, modeled_height, color, w->width, w->height, x_prop, y_prop);
	x = 0;
	while (x < modeled_width)
	{
		printf("w1 : %f < %f\n", x, modeled_width);
		run = dl;
		while (run && x > run->vert->v.x)
		{
			printf("w2 : %f > %f\n", x, run->vert->v.x);
			i = -1;
			count = 0;
			while (++i < 4)
			{
				printf("w3 : %d\n", i);
				run->vert->done = true;
				if (!run->vert->next[i] || run->vert->next[i]->done)
				{
					count++;
					continue ;
				}
				m = (run->vert->next[i]->v.y - run->vert->v.y)
					/ (run->vert->next[i]->v.x - run->vert->v.x);
				p = run->vert->v.y - m * run->vert->v.x;
				printf("y = %fx + %f\n", m, p);
				printf("set_pxl_img(%s, %d, %d, %d)\n", w->name, (int)(x / x_prop), (int)((m * x + p) / y_prop),
					color);
				set_pxl_img(w, (int)(x / x_prop), (int)((m * x + p) / y_prop),
					color);
			}
			if (count == 4 && run == dl)
				dl = dl->next;
			run = run->next;
		}
		x += x_prop;
	}
	mlx_put_image_to_window(w->mlx_ptr, w->win_ptr, w->img->img_ptr, 0, 0);
}
