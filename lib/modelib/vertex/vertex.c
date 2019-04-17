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

# include "modeling.h"

vertex			*new_vertex(ve *coord, int i)
{
	vertex *r;

	if (!(r = (vertex*)malloc(sizeof(vertex))))
		return (NULL);
	r->coord = *coord;
	r->prime = *coord;
	r->next = NULL;
	r->color = 255;
	r->pos = i;
	return (r);
}

vertex			*add_vertex(vertex *list, ve *coord, int i)
{
	vertex *r;

	if (!(r = new_vertex(coord, i)))
	{
		free_vertex(&list);
		return (NULL);
	}
	r->next = list;
	return (r);
}

void			free_vertex(vertex **list)
{
	vertex *run;

	if (!list || !*list)
		return ;
	run = (*list)->next;
	free(*list);
	*list = NULL;
	free_vertex(&run);
}
