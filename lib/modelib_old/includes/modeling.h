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
	ve					v;
	ve					vprime;
	struct s_vertex		*next[4];
	char				*color;
	bool				done;
}				vertex; //(n)

typedef struct	s_drawing_list
{
	struct s_vertex			*vert;
	struct s_drawing_list	*next;
}				drawing_list; //(n)

/*
** --- Vertex ---
*/

vertex			*new_vertex(ve v, vertex *rvert);
bool			add_vertex(vertex *grid, ve new_vertex, ve link);
void			rm_vertex(vertex *to_rm);
void			free_vertex(vertex *grid); //(ni)

void			apply_vertex(void (*f)(vertex *vert), vertex *grid);
void			reset_vertex(vertex *grid);

void			link_vertex(vertex *a, vertex *b);
void			rmlink_vertex(vertex *a, vertex *b);

vertex			*find_vertex(ve v, vertex *grid);

/*
** --- DrowingList ---
*/

drawing_list	*new_drawing_list(vertex *vert);
bool			insert_drawing_list(drawing_list **dl, vertex *vert);
void			free_drawing_list(drawing_list **dl);

drawing_list	*organise(vertex *grid);
void			reorganise(drawing_list **dl);

void			draw(window *w, drawing_list *dl,
					double modeled_width, double modeled_height, int color);

#endif
