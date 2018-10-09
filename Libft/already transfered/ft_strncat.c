/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 13:48:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 13:52:47 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < n && src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int main(void)
{
	char test[300], *test1;

	test[0] = 'a';
	test1 = " dit is een test om een zin toe te voegen";

	printf("%s", ft_strncat(test, test1, 500));
}

