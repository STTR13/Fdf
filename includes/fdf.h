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
# include "../lib/minilibx_macos/mlx.h"
# include "../lib/geolib/includes/geometry.h"
# include "../lib/modelib/includes/modeling.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define WHEIGHT 1280
# define WWIDTH 2280
# define COLORWHITE 0xaabbcc

typedef struct			s_input
{
	int **input;
	int lines;
	int linelen;
}						t_input;

typedef struct			s_wlist
{
	void	*mlx_ptr;
	void	*win_ptr;
	tinput	*file;
}						t_wlist;

int						deal_key(int key, twlist *window);
int						mouse_key(int key, twlist *window);
void					window_init(twlist *window);
tinput					*file_reader(int fd);
void					free_all(vertex *v, tinput *file);
int						windowclose(twlist *window);
int						mouse_move(int x, int y, twlist *window);
vertex					*veconvertstart(tinput *file, int x, int y);

#endif
