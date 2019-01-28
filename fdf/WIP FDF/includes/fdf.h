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
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			sinput
{
	int **input;
	int lines;
	int linelen;
	struct sinput *next;
}										tinput;

typedef struct			swlist
{
	void	*mlx_ptr;
	void	*win_ptr;
	tinput	*file;
}						twlist;

int deal_key(int key, twlist *window);
int mouse_key(int key, twlist *window);
void window_init(twlist *window);
tinput	*file_reader(int fd);
tinput *character_convertor(tinput *lst, char *temp);
int validinput(char *temp);
int **filecreator(char *temp, int lines, int linelen);
int linecounter(char *str);
twlist *free_list(twlist *window);
int windowclose(twlist *window);
int mouse_move(int x, int y, twlist *window);


#endif
