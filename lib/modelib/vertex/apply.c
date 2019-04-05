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

# include "modeling.h"

void			apply_vertex(void (*f)(vertex *vert), vertex *list)
{
	if (!list)
		return ;
	(*f)(list);
	apply_vertex(f, list->next);
}

vertex			*find_vertex(vertex *list, ve coord)
{
	if (!list)
		return (NULL);
	if (equal_x_y(list->coord, coord))
		return (list);
	return (find_vertex(list->next, coord));
}
