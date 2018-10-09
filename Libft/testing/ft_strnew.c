/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:03:32 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 13:19:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strnew(size_t size)
{
	char	*tmem;

    if (size == 0)
        return (NULL);
	 tmem = (char *)malloc(sizeof(char) * (size + 1));
	 
	ft_memset(tmem, '\0', size);
	return (tmem);
}
