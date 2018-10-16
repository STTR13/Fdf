/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:30:10 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 11:33:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	//if (str[i] != '\0')
		return ((char *)&str[i]);
	/*else
		return (NULL);*/
}
int main(void)
{
	char *str, str2, *str3;

	str = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
	str2 = '\0';
	str3 = ft_strchr(str, str2);
	printf("%s", str3);
	return (0);
}
