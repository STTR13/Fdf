/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intarrclr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:15:51 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/01/28 11:18:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		**ft_intarrclr(int **ap)
{
	int i;

	i = 0;
	if (ap && *ap)
	{
		while (ap[i])
		{
			free(ap[i]);
			ap[i] = NULL;
			i++;
		}
	free(ap);
	ap = NULL;
	return (ap);
	}
	if (ap)
		free (ap);
	return (ap);
}
