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

void			draw(window *w, drawing_list *dl,
					double modeled_width, double modeled_height, int color)
{
	int	i, count;
	double x, x_prop, y_prop, m, p;
	drawing_list	*run;

	x_prop = modeled_width / (double)(w->width);
	y_prop = modeled_height / (double)(w->height);
	x = 0;
	while (x < modeled_width)
	{
		run = dl;
		while (run && x > run->vert->vprime.x)
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
				m = (run->vert->next[i]->vprime.y - run->vert->vprime.y)
					/ (run->vert->next[i]->vprime.x - run->vert->vprime.x);
				p = run->vert->vprime.y - m * run->vert->vprime.x;
				set_pxl_img(w, (int)(x / x_prop), (int)((m * x + p) / y_prop),
					color);
			}
			if (count == 4 && run == dl)
				dl = dl->next;
			run = run->next;
		}
		x += x_prop;
	}
	reset_vertex(dl->vert);
}
