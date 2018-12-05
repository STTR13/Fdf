/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:17:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/24 21:29:24 by agilmet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmem;

	if (((tmem = malloc(size)) == NULL) || size == 0)
		return (NULL);
	else
		return (ft_memset(tmem, 0, size));
}
