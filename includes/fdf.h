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

/*
** --- File reader and data organization ---
*/

int						get_next_line_opti(int fd, char **line);
char					*reader(int filedesc);

t_input					*file_reader_fdf(int fd);
t_bool					file_reader_obj(int fd, t_warehouse *wh);
void					errormessage(int i, t_warehouse *window);
int						get_color_grad(double percent, t_edge *e);
void					free_all(t_warehouse *w);

/*
** --- Window ---
*/

void					window_init_load(t_warehouse *window);
void					refresh_win(t_warehouse *wl);

/*
** --- Keys and Mouse ---
*/

int						deal_key(int key, t_warehouse *window);

/*
** --- Hook ---
*/

int						expose(void *window);
int						windowclose(void *window);
int						mouse_press(int key, int x, int y, void *window);
int						key_press(int key, void *window);
int						mouse_move(int x, int y, void *window);
int						key_release(int key, void *window);
int						loop_hook(void *param);

#endif
