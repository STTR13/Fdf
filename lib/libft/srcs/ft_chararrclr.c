/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:04:21 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/01/28 11:09:28 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	**ft_chararrclr(char **ap, int length)
{
	int i;

	length = 0;
	i = 0;
	if (ap && *ap)
	{
		while (ap[i])
		{
			ft_strdel(&ap[i]);
			i++;
		}
		free(ap);
		return (ap);
	}
	if (ap)
		free(ap);
	return (ap);
}
