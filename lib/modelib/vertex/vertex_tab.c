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

t_vertex			**new_vertex_tab(t_vertex *list_head, int count)
{
	t_vertex			**ret;

	if (!count || !(ret = (t_vertex**)malloc(sizeof(t_vertex*) * (count + 1))))
		return (NULL);
	ret[count] = NULL;
	while(--count >= 0)
	{
		ret[count] = list_head;
		list_head = list_head->next;
	}
	return (ret);
}

void			free_vertex_tab(t_vertex ***tab)
{
	free(*tab);
	*tab = NULL;
}
