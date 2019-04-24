/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:56:03 by staeter           #+#    #+#             */
/*   Updated: 2019/04/04 15:56:05 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

t_vertex	*new_vertex(t_ve *coord, int i)
{
	t_vertex	*r;

	if (!(r = (t_vertex*)malloc(sizeof(t_vertex))))
		return (NULL);
	r->coord = *coord;
	r->prime = *coord;
	r->next = NULL;
	r->color = 255;
	r->pos = i;
	return (r);
}

t_vertex	*add_vertex(t_vertex *list, t_ve *coord, int i)
{
	t_vertex	*r;

	if (!(r = new_vertex(coord, i)))
	{
		free_vertex(&list);
		return (NULL);
	}
	r->next = list;
	return (r);
}

void		free_vertex(t_vertex **list)
{
	t_vertex	*run;

	if (!list || !*list)
		return ;
	run = (*list)->next;
	free(*list);
	*list = NULL;
	free_vertex(&run);
}
