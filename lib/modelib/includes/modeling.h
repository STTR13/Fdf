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

# include <stdlib.h>

# include "symlink_geolib_includes/geometry.h"
# include "symlink_visualib_includes/visual.h"

typedef struct	s_vertex
{
	ve					coord;
	ve					prime;
	struct s_vertex		*next;
	int					color;
}				vertex; //(n)

typedef struct	s_edge
{
	vertex				*vert1;
	vertex				*vert2;
	struct s_edge		*next;
}				edge;

/*
** --- Vertex ---
*/

vertex			*new_vertex(ve coord);
vertex			*add_vertex(vertex *list, ve coord);
void			free_vertex(vertex **list);

void			apply_vertex(void (*f)(vertex *vert, void *param), vertex *list,
					void *param);
vertex			*find_vertex(vertex *list, ve coord);

/*
** --- Edge ---
*/

edge			*new_edge(vertex *vert1, vertex *vert2);
edge			*add_edge(edge *list, vertex *vert1, vertex *vert2);
void			free_edge(edge **list);

void			apply_edge(void (*f)(edge *vert, void *param),
					edge *list, void *param);
void			draw_edge(window *w, edge *ed);
void			draw_model(window *w, edge *list);

#endif
