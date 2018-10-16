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
	int i;
	int j;

	i = ft_strlen(dest);
	j = -1;
	while (++j < (int)size && src[j] != '\0')
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (i + j);
}

int main(void)
{
    char *src = "aaa";
    char dst1[20];
		//test[0] = 'a';
    //test1 = " dit is een test om een zin toe te voegen";

    printf("%zu", ft_strlcat(dst1, src, 20));
}
