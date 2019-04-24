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

typedef struct		s_vertex
{
	int				pos;
	t_ve			coord;
	t_ve			prime;
	struct s_vertex	*next;
	int				color;
}					t_vertex;

typedef struct		s_edge
{
	t_vertex		*vert1;
	t_vertex		*vert2;
	struct s_edge	*next;
}					t_edge;

typedef struct		s_input
{
	char			**input;
	int				lines;
	int				linelen;
}					t_input;

typedef struct		s_warehouse
{
	t_input			*file;
	t_vertex		*v;
	t_vertex		**tab;
	t_edge			*e;
	t_window		*w;
	t_pl			p;
	double			eye;
	t_matrix		sysmat;
	t_bool			mode;
	t_bool			mouse;
}					t_warehouse;

/*
** --- Vertex ---
*/

t_vertex			*new_vertex(t_ve *coord, int i);
t_vertex			*add_vertex(t_vertex *list, t_ve *coord, int i);
void				free_vertex(t_vertex **list);

void				apply_vertex(void (*f)(t_vertex *vert, void *param),
					t_vertex *list, void *param);
t_vertex			*find_vertex(t_vertex *list, t_ve *coord);
t_vertex			*find_vertex_pos(t_vertex *list, int pos);

/*
** --- Vertex_Tab ---
*/

t_vertex			**new_vertex_tab(t_vertex *list_head, int count);
void				free_vertex_tab(t_vertex ***tab);

/*
** --- Edge ---
*/

t_edge				*new_edge(t_vertex *vert1, t_vertex *vert2);
t_edge				*add_edge(t_edge *list, t_vertex *vert1, t_vertex *vert2);
void				free_edge(t_edge **list);

void				apply_edge(void (*f)(t_edge *vert, void *param),
					t_edge *list, void *param);
void				draw_edge(t_window *w, t_edge *ed);
void				draw_model(t_window *w, t_edge *list);

/*
** --- File Organizer ---
*/

t_vertex			*veconvertstart(t_input *file);
t_edge				*edgefiller(t_input *f, t_vertex **vt);
t_edge				*edgefiller_obj(t_warehouse *wh, int *x, int j);

/*
** --- Warehouse ---
*/

void				init_warehouse(t_warehouse *wh);
void				free_all(t_warehouse *wh);

void				refresh_win(t_warehouse *wl);

#endif
