/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:59:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/06 09:59:06 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	window_init(t_wlist *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WWIDTH, WHEIGHT, "FDF");
	int i = 0;
	int x = 0;
	int j = 10;
	while (i <= window->file->lines * window->file->linelen)
	{
		while (x < window->file->linelen)
		{
			if (window->v->color == NULL)
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->v->v.x * 10, window->v->v.y * 10, 255);
			else
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, window->v->v.x * 10, window->v->v.y * 10, ft_hexaconverter(window->v->color));
			x++;
			i++;
			window->v++;
		}
		j += 1;
		x = 0;
		i++;
	}

	/*int i;
	i = -1;
	while (++i < window->file->linelen * window->file->lines)
	{
		printf("x: %f\ny: %f\nz: %f\ncolor: %i\n", window->v->v.x, window->v->v.y, window->v->v.z, window->v->color);
		if (window->v->next[0])
			printf("Vector to the right: x: %f, y: %f, z: %f\n", window->v->next[0]->v.x, window->v->next[0]->v.y, window->v->next[0]->v.z);
		if (window->v->next[1])
			printf("Vector to the bottom: x: %f, y: %f, z: %f\n", window->v->next[1]->v.x, window->v->next[1]->v.y, window->v->next[1]->v.z);
		if (window->v->next[2])
			printf("Vector to the left: x: %f, y: %f, z: %f\n", window->v->next[2]->v.x, window->v->next[2]->v.y, window->v->next[2]->v.z);
		if (window->v->next[3])
			printf("Vector to the top: x: %f, y: %f, z: %f\n", window->v->next[3]->v.x, window->v->next[3]->v.y, window->v->next[3]->v.z);
		printf("\n");
		window->v++;
	}*/

	/*mlx_hook(window->win_ptr, 2, (1L << 0), deal_key, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_key, window);
	mlx_hook(window->win_ptr, 6, (1L << 13), mouse_move, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), windowclose, window);*/
	mlx_loop(window->mlx_ptr);
}
