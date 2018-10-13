/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 14:31:29 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/02 14:39:58 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int		length;

	length = 0;
	i = 0;
	while (src[length] != '\0')
		length++;
	str = (char*)malloc(sizeof((*str) * (length + 1)));
	while (i < length)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int main(void)
{
	char *str, *str2;
	str = "dit is een test";
	str2 = ft_strdup(str);
	printf("%s\n%s", str, str2);
}
