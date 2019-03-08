/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:58:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/06 09:58:55 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void free_tinput(tinput *file)
{
	ft_intarrclr(file->input);
	file->lines = 0;
	file->linelen = 0;
	//free(file);
}
