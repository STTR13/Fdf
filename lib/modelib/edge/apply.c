/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:53:55 by staeter           #+#    #+#             */
/*   Updated: 2019/04/04 16:53:56 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "modeling.h"

void		apply_edge(void (*f)(t_edge *vert, void *param), t_edge *list, void *param)
{
	if (!list)
		return ;
	(*f)(list, param);
	apply_edge(f, list->next, param);
}

void		draw_edge(t_window *w, t_edge *ed)
{
	int coord[2][2];
	int color[2];

	if (ed->vert1->prime.z < 0 || ed->vert2->prime.z < 0)
		return ;
	coord[0][0] = (ed->vert1->prime.y * 50) + (w->width / 2);
	coord[0][1] = (ed->vert1->prime.x * -50) + (w->height / 2);
	coord[1][0] = (ed->vert2->prime.y * 50) + (w->width / 2);
	coord[1][1] = (ed->vert2->prime.x * -50) + (w->height / 2);
	color[0] = ed->vert1->color;
	color[1] = ed->vert2->color;
	draw_line_img(w, coord, color);
}

static void	draw_edge_s(t_edge *ed, void *param)
{
	draw_edge((t_window*)param, ed);
}

void		draw_model(t_window *w, t_edge *list)
{
	apply_edge(&draw_edge_s, list, (void*)w);
}
