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

static void		free_v(vertex *v, t_input *file)
{
	int i;

	i = file->lines * file->linelen;
	v += i;
	while (--i >= 0)
	{
		if (v)
		{
			v->v.x = 0;
			v->v.y = 0;
			v->v.z = 0;
			if (v->color != NULL)
				ft_strdel(&v->color);
			v->next[0] = NULL;
			v->next[1] = NULL;
			v->next[2] = NULL;
			v->next[3] = NULL;
			v--;
		}
	}
	free(v);
}

static void		free_i(t_input *file)
{
	if (file->input)
		ft_chararrclr(file->input, file->linelen * file->lines);
	file->lines = 0;
	file->linelen = 0;
	free(file);
}

void			free_all(t_wlist *w)
{
	if (w->v && w->file)
		free_v(w->v, w->file);
	if (w->file != NULL)
		free_i(w->file);
}
