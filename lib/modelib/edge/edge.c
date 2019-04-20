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

t_edge			*new_edge(t_vertex *vert1, t_vertex *vert2)
{
	t_edge *r;

	if (!(r = (t_edge*)malloc(sizeof(t_edge))))
		return (NULL);
	r->vert1 = vert1;
	r->vert2 = vert2;
	r->next = NULL;
	return (r);
}

t_edge			*add_edge(t_edge *list, t_vertex *vert1, t_vertex *vert2)
{
	t_edge *r;

	if (!(r = new_edge(vert1, vert2)))
	{
		free_edge(&list);
		return (NULL);
	}
	r->next = list;
	return (r);
}

void			free_edge(t_edge **list)
{
	t_edge *run;

	if (!list || !*list)
		return ;
	run = (*list)->next;
	free(*list);
	*list = NULL;
	free_edge(&run);
}
