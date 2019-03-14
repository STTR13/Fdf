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
	char	**input;
	int		lines;
	int		linelen;
}						t_input;

typedef struct			s_wlist
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_input	*file;
}						t_wlist;

int						deal_key(int key, t_wlist *window);
int						mouse_key(int key, t_wlist *window);
void					window_init(t_wlist *window);
t_input					*file_reader(int fd);
void					free_all(vertex *v, t_input *file);
int						windowclose(t_wlist *window);
int						mouse_move(int x, int y, t_wlist *window);
vertex					*veconvertstart(t_input *file, int x, int y);

#endif
