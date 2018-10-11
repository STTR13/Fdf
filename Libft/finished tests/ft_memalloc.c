/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 12:17:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 13:01:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tmem;

    if (size == 0)
        return (NULL);
    tmem = malloc(size);
	ft_memset(tmem, 0, size);
	return (tmem);
}

int main(void)
{
	char *str;

	char = ft_memalloc(10);
	return (0);
}
