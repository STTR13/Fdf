/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:54:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 13:59:12 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (size > 0)
	{
	while (dest[i] && i < size)
		i++;
	j = i;
	while (src[i - j] && i < size - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
}
	if (j < size)
		dest[i] = '\0';
	return (i + ft_strlen(src));
}


int main(void)
{
    char *src = "the cake is a lie !\0I'm hidden lol\r\n";
    char dst1[0xF00] = "there is no stars in the sky";
		size_t max = ft_strlen("the cake is a lie !\0I'm hidden lol\r\n");
		//test[0] = 'a';
    //test1 = " dit is een test om een zin toe te voegen";

    printf("%zu", ft_strlcat(dst1, src, max));
}
