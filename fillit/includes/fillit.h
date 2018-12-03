/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:50:40 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/03 11:18:29 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_pos
{
	int		x;
	int		y;
}					t_pos;

typedef struct		s_tetri
{
	int				counter;
	char			c;
	t_pos			*p0;
	t_pos			*p1;
	t_pos			*p2;
	t_pos			*p3;
	struct s_tetri	*next;
}					t_tetri;

t_tetri				*file_reader(int fd);
int					connections(char *str);
int					checker(char *str, int counter);
t_tetri				*new_piece(char *str, char value,\
						t_tetri *piece, int counter);
t_tetri				*insert_piece(char **arr, t_tetri *piece);
t_tetri				*ft_put_position(t_tetri *piece, t_pos *pos, int count);
int					ft_find_size(t_tetri *l);
int					ft_calculate(int count, t_tetri *l);
int					ft_calculate_bis(int count);
char				**ft_reset(char **tab, t_tetri *l, t_pos p);
int					ft_conditions(char ***tab, t_tetri *l, t_pos p, int size);
int					ft_put_tetri(char ***tab, t_tetri *l, int size);
char				**ft_solver(t_tetri *lst, int size);
char				**ft_newtab(int size);
void				printmap(char **map);
t_tetri				*list_creator(t_tetri *begin, int fd);
t_tetri				*piece_creator(t_tetri *begin, char *buffer,\
						char cl, int counter);
t_tetri				*delete_pieces(t_tetri *begin);
void				ft_memdell(void *ap);
char				**ft_arrclr(char **ap);
int					last_cluster(t_tetri *l);

#endif
