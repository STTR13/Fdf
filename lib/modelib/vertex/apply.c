/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:17:45 by staeter           #+#    #+#             */
/*   Updated: 2019/04/04 16:17:47 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

void		apply_vertex(void (*f)(t_vertex *vert, void *param),\
			t_vertex *list, void *param)
{
	if (!list)
		return ;
	(*f)(list, param);
	apply_vertex(f, list->next, param);
}

t_vertex	*find_vertex(t_vertex *list, t_ve *coord)
{
	if (!list)
		return (NULL);
	if (list->coord.x == coord->x && list->coord.y == coord->y)
		return (list);
	return (find_vertex(list->next, coord));
}

t_vertex	*find_vertex_pos(t_vertex *list, int pos)
{
	if (!list)
		return (NULL);
	if (list->pos == pos)
		return (list);
	return (find_vertex_pos(list->next, pos));
}
