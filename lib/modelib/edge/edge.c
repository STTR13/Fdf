/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edge.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:47:33 by staeter           #+#    #+#             */
/*   Updated: 2019/04/04 16:47:35 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "modeling.h"

edge			*new_edge(vertex *vert1, vertex *vert2)
{
	edge *r;

	if (!(r = (edge*)malloc(sizeof(edge))))
		return (NULL);
	r->vert1 = vert1;
	r->vert2 = vert2;
	r->next = NULL;
	return (r);
}

edge			*add_edge(edge *list, vertex *vert1, vertex *vert2)
{
	edge *r;

	if (!(r = new_edge(vert1, vert2)))
	{
		free_edge(&list);
		return (NULL);
	}
	r->next = list;
	return (r);
}

void			free_edge(edge **list)
{
	edge *run;

	if (!list || !*list)
		return ;
	run = (*list)->next;
	free(*list);
	*list = NULL;
	free_edge(&run);
}
