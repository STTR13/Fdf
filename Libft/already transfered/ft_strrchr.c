/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:34:30 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 11:40:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	int		j;
	char	*temp;
    
    j = 0;
    i = ft_strlen(str);
	while (str[i] != c && i > 0)
		i--;
	if (str[i] == c)
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
    str2 = '.';
    str3 = ft_strrchr(str, str2);
    printf("%s", str3);
    return (0);
}
