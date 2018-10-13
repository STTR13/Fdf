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

char	*ft_strchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	if (str[i] != '\0')
	{
		while (str[i] != '\0')
		{
			temp[j] = str[i];
			i++;
			j++;
		}
		temp[j] = '\0';
		return (temp);
	}
	else
		return (NULL);
}
int main(void)
{
	char *str, str2, *str3;

	str = "dit is een test.";
	str2 = 't';
	str3 = ft_strchr(str, str2);
	printf("%s", str3);
	return (0);
}
