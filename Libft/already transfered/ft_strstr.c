/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:53:55 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 16:04:31 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
char	*ft_strstr(char *haystack, const char *needle)
{
	int x;
	int c;

	x = 0;
	while (haystack[x])
	{
		c = 0;
		while (needle[c] == haystack[c + x])
		{
			if (needle[c + 1] == '\0')
			{
				return (haystack + x);
			}
			c++;
		}
		x++;
	}
	return (NULL);
}

int main(void)
{
	char *str1, *str2;

	str1 = "dit is een test";
	str2 = "is";
	printf("%s", ft_strstr(str1, str2));
	return (0);
}
