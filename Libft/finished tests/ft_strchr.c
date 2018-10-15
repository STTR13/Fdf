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
	int		j;
	char	*temp;
	char	*result;

	i = 0;
	j = 0;
	temp = (char *)str;
	while (temp[i] != c && temp[i] != '\0')
		i++;
	if (temp[i] != '\0')
	{
		while (temp[i] != '\0')
		{
			result[j] = temp[i];
			i++;
			j++;
		}
		result[j]  = '\0';
		return (result);
	}
	else
		return (NULL);
}
int main(void)
{
	char *str, str2, *str3;

	str = "dit is een test.";
	str2 = '.';
	str3 = ft_strchr(str, str2);
	printf("%s", str3);
	return (0);
}
