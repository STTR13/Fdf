/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:44:22 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/01/18 12:50:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../lib/libft/includes/get_next_line.h"
# include "symlink_geolib_includes/geometry.h"
# include "symlink_modelib_includes/modeling.h"
# include "symlink_visualib_includes/visual.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WHEIGHT 1280
# define WWIDTH 2280
# define COLORWHITE 0xaabbcc

typedef struct			s_input
{
	char	**input;
	int		lines;
	int		linelen;
}						t_input;

typedef struct			s_wlist
{
	t_input			*file;
	vertex			*v;
	edge			*e;
	//drawing_list	*dl;
	window 			*w;
	ve 				mouse_last_pos;
}						t_wlist;

int						deal_key(int key, t_wlist *window);
int						mouse_key(int key,  int x, int y, void *window);
int						windowclose(void *window);
void					window_init_load(t_wlist *window);
void					free_all(t_wlist *w);
void					xlink(vertex *grid, t_input *file);
void					ylink(vertex *grid, t_input *file);
vertex					*veconvertstart(t_input *file, int x, int y);
t_input					*file_reader(int fd);
void					key_move(int key, t_wlist *window);
void					key_zoom(int key, t_wlist *window);
void					change_view(int key, t_wlist *window);
void					z_valuechange(int key, t_wlist *window);
int						key_press_all(int key, void *window);
int						mouse_move(int x, int y, void *window);
edge					*edgefiller(t_input *f, vertex *v, int x, int y);
ve						createv(int z, int x, int y);


#endif
