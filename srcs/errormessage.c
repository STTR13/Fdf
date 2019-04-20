/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormessage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:58:48 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:48:40 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** frees every malloc
*/

void		errormessage(int i, t_warehouse *wh)
{
	if (i == 1)
	{
		ft_putendl("usage: ./fdf input_file");
		exit(0);
	}
	else if (i == 2)
	{
		free_all(wh);
		ft_putendl("error");
		exit(0);
	}
	else if (i == 3)
	{
		free_all(wh);
		ft_putendl("wrong file type");
		exit(0);
	}
}
