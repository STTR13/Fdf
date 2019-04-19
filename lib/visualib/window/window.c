/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:06:44 by staeter           #+#    #+#             */
/*   Updated: 2019/03/07 12:06:45 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

t_window			*new_window(char *name, int width, int height)
{
	t_window *rw;

	if (!name || width < 0 || height < 0 ||
		!(rw = (t_window*)malloc(sizeof(t_window))))
		return (NULL);
	if (!(rw->mlx_ptr = mlx_init()) ||
		!(rw->win_ptr = mlx_new_window(rw->mlx_ptr, width, height, name)) ||
		!(rw->width = width) || !(rw->height = height) ||
		!new_img(rw))
	{
		free_window(rw);
		return (NULL);
	}
	rw->name = name;
	rw->hook.key_press = NULL;
	rw->hook.key_release = NULL;
	rw->hook.mouse_press = NULL;
	rw->hook.mouse_release = NULL;
	rw->hook.mouse_move = NULL;
	rw->hook.expose = NULL;
	rw->hook.close = NULL;
	rw->hook.param = rw;
	return (rw);
}

void			free_window(t_window *w)
{
	//free(w->name);
	free_img(w);
	mlx_destroy_window(w->mlx_ptr, w->win_ptr);
	free(w);
	w = NULL;
}
