/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:04:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/12/01 12:16:21 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	printmap(char **map)
{
	int size;
	int i;

	i = 0;
	size = ft_strlen(map[0]);
	while (i < size)
	{
		ft_putendl(map[i]);
		i++;
	}
}
