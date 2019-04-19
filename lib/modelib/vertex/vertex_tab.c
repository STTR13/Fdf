/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:36:43 by staeter           #+#    #+#             */
/*   Updated: 2019/04/19 14:36:44 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

static void		listlen_s(vertex *list_head, unsigned int *count)
{
	if (!list_head)
		return ;
	(*count)++;
	listlen_s(list_head, count);
}

vertex			**new_vertex_tab(vertex *list_head)
{
	vertex			**ret;
	unsigned int	count;

	count = 0;
	listlen_s(list_head, &count);
	if (!count || !(ret = (vertex**)malloc((count + 1) * sizeof(vertex*))))
		return (NULL);
	ret[count] = NULL;
	while(--count)
	{
		ret[count] = list_head;
		list_head = list_head->next;
	}
	return (ret);
}

void			free_vertex_tab(vertex ***tab)
{
	free(*tab);
	*tab = NULL;
}
