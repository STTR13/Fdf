/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modeling.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 11:43:27 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 11:43:28 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODELING_H
# define MODELING_H

# include "../geolib/geometry.h"

/*
** --- Vertex ---
*/

typedef struct	s_vertex
{
	ve			v;
	struct vertex		*next[4];
	bool		done;
}				vertex; //(n)

vertex			new_vertex(ve v);
bool			add_vertex(vertex *grid, ve new_vertex, ve link);
bool			rm_vertex(vertex *to_rm);

void			reset_vertex(vertex *vert);
void			link_vertex(vertex *a, vertex *b);
void			apply_vertex(void (*f)(vertex *vert), vertex *grid);
vertex			find_vertex(ve v, vertex *grid);

#endif
