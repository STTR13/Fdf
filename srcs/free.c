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
		v->v.x = (int)NULL;
		v->v.y = (int)NULL;
		v->v.z = (int)NULL;
		v->color = NULL;
		v->next[0] = NULL;
		v->next[1] = NULL;
		v->next[2] = NULL;
		v->next[3] = NULL;
		v--;
	}
	ft_memdell(v);
}

void			free_all(vertex *v, t_input *file)
{
	if (v && file)
		free_v(v, file);
	if (file && file->input)
		ft_chararrclr(file->input);
	if (file)
	{
		file->lines = 0;
		file->linelen = 0;
		ft_memdell(file);
	}
}
