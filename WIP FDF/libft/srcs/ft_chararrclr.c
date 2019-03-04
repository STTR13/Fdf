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

char	**ft_chararrclr(char **ap)
{
	int i;

	i = ft_strlen(ap[0] - 1);
	if (ap && *ap)
	{
		while (i >= 0)
		{
			free(ap[i]);
			ap[i] = NULL;
			i--;
		}
		free(ap);
		ap = NULL;
		return ((ap));
	}
	if (ap)
		free(ap);
	return (ap);
}
