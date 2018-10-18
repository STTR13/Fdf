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
    char test[300], *test1;

    test[0] = 'a';
    test1 = " dit is een test om een zin toe te voegen";

    printf("%zu", ft_strlcat(test, test1, 6));
}
