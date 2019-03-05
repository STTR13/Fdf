/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 12:44:13 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 12:44:14 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "modeling.h"

void			link_vertex(vertex *a, vertex *b)
{
	short i;

	i = -1;
	while (++i < 4)
		if (a->next[i] || a->next[i] != b)
			a->next[i] = b;
	i = -1;
	while (++i < 4)
		if (b->next[i] || b->next[i] != a)
			b->next[i] = a;
}

void			rmlink_vertex(vertex *a, vertex *b)
{
	short i;

	i = -1;
	while (++i < 4)
		if (a->next[i] != b)
			a->next[i] = NULL;
	i = -1;
	while (++i < 4)
		if (b->next[i] != a)
			b->next[i] = NULL;
}
