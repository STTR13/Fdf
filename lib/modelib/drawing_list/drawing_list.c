/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:51:47 by staeter           #+#    #+#             */
/*   Updated: 2019/03/06 13:51:49 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

drawing_list	*new_drawing_list(vertex *vert)
{
	drawing_list *rdl;

	if (!(rdl = (drawing_list*)malloc(sizeof(drawing_list))))
		return (NULL);
	rdl->next = NULL;
	rdl->vert = vert;
	return (rdl);
}

static bool		insert_drawing_list_sub(drawing_list **dl,
	drawing_list **ndl, vertex *vert)
{
	if (!(*nld = new_drawing_list(vert)))
	{
		free_drawing_list(dl);
		return (false);
	}
	return (true);
}

bool			insert_drawing_list(drawing_list **dl, vertex *vert)
{
	drawing_list *ndl;
	drawing_list *run;

	if (*dl->vert->v->x > vert->v->x)
	{
		if (!insert_drawing_list_sub(dl, &nld, vert))
			return (false);
		nld->next = *dl;
		*dl = nld;
	}
	else
	{
		run = *dl;
		while (1)
			if (!run->next || run->next->vert->v->x > vert->v->x)
				break ;
		if (!insert_drawing_list_sub(dl, &nld, vert))
			return (false);
		nld->next = run->next;
		run->next = nld;
	}
	return (true);
}

void			free_drawing_list(drawing_list **dl)
{
	if (*dl->next)
		free_drawing_list(&(*dl->next));
	free(*dl);
	dl = NULL;
}
