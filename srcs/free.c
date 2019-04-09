/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:58:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:48:40 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


static void	free_i(t_input *file)
{
	if (file->input)
		ft_chararrclr(file->input, file->linelen * file->lines);
	file->lines = 0;
	file->linelen = 0;
	free(file);
}

void			free_all(t_wlist *w)
{
	if (w->w)
		free_window(w->w);
	if (w->e)
		free_edge(&w->e);
	if (w->v)
		free_vertex(&w->v);
	if (w->file)
		free_i(w->file);
}
