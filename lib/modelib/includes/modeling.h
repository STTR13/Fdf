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
# include "../../libft/includes/get_next_line.h"

typedef struct	s_vertex
{
	int					pos;
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

typedef struct			s_input
{
	char				**input;
	int					lines;
	int					linelen;
}						t_input;

typedef struct			s_warehouse
{
	t_input				*file;
	vertex				*v;
	edge				*e;
	window 				*w;
	int					mouse_last_pos[2];
	pl					p;
	double				eye; // tjrs pos
	matrix				sysmat;
	bool				mode;
	bool				mouse;
}						warehouse;

/*
** --- Vertex ---
*/

vertex			*new_vertex(ve *coord, int i);
vertex			*add_vertex(vertex *list, ve *coord, int i);
void			free_vertex(vertex **list);

void			apply_vertex(void (*f)(vertex *vert, void *param), vertex *list,
					void *param);
vertex			*find_vertex(vertex *list, ve *coord);
vertex			*find_vertex_pos(vertex *list, int pos);

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

/*
** --- File Organizer ---
*/

vertex			*veconvertstart(t_input *file);
edge			*edgefiller(t_input *f, vertex *v);
ve				*createv(double z, double x, double y, ve *ret);

/*
** --- Warehouse ---
*/

void			init_warehouse(warehouse *wh);
void			free_all(warehouse *wh);

void			refresh_win(warehouse *wl);

#endif
