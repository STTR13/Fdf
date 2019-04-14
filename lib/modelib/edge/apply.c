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

void		apply_edge(void (*f)(edge *vert, void *param), edge *list, void *param)
{
	if (!list)
		return ;
	(*f)(list, param);
	apply_edge(f, list->next, param);
}

void		draw_edge(window *w, edge *ed)
{
	int coord[2][2];

	if (ed->vert1->prime.z < 0 || ed->vert2->prime.z < 0)
		return ;
	coord[0][0] = ed->vert1->prime.x;
	coord[0][1] = ed->vert1->prime.y;
	coord[1][0] = ed->vert2->prime.x;
	coord[1][1] = ed->vert2->prime.y;
	draw_line_img(w, coord);
}

static void	draw_edge_s(edge *ed, void *param)
{
	draw_edge((window*)param, ed);
}

void		draw_model(window *w, edge *list)
{
	apply_edge(&draw_edge_s, list, (void*)w);
}
