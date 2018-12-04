/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 12:44:22 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 15:01:00 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct			s_coords
{
	int x;
	int y;
}										t_coords;

typedef struct			swlist
{
	char *file;
	void	*mlx_ptr;
	void	*win_ptr;
	int color;
}						twlist;

int deal_key(int key, twlist *window);
int mouse_key(int key, twlist *window);
void window_init(twlist *window);

#endif
