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
void					free_all(t_warehouse *w);

/*
** --- Window ---
*/

void					window_init_load(t_warehouse *window);
void					refresh_win(t_warehouse *wl);

/*
** --- Hook ---
*/

int						expose(void *wh);
int						windowclose(void *wh);
int						mouse_press(int key, int x, int y, void *wh);
int						key_press(int key, void *wh);
int						mouse_move(int x, int y, void *wh);
int						key_release(int key, void *wh);
int						loop_hook(void *param);

#endif
