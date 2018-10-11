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
size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	while (dest[i])
		i++;
	while (j < n && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + j);
}

int main(void)
{
    char test[300], *test1;
    
    test[0] = 'a';
    test1 = " dit is een test om een zin toe te voegen";
    
    printf("%zu", ft_strlcat(test, test1, 6));
}
