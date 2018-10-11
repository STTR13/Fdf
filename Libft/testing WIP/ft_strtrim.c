/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:23:59 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 13:20:25 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strtrim(char const *s)
{
	int		i;
	int		l;
    char	*final, *temp;

	i = 0;
	l = 0;
    final = (char *)s;
    temp = NULL;
	while (s[i] != '\0')
	{
		if (s[i] != ' ' && s[i] != ',' && s[i] != '\n' && s[i] != '\t')
        {
     //       temp[l] = s[i];
            l++;
        }
		i++;
	}
    /*if (l == i)
        temp = "test";*/
    final = ft_strnew(l);
	i = 0;
    l = 0;
    while (s[i] != '\0')
    {
        if (s[i] != ' ' && s[i] != ',' && s[i] != '\n' && s[i] != '\t')
        {
            final[l] = s[i];
            l++;
        }
		i++;
	}
	final[l] = '\0';
	return (final);
}

int main(void)
{
	char *str, *str2;
    int i;
	str = "   ,,,\n\n\n\t\t\t   dit is een\ntest   ,,, \n\n\n\t\t\t\n";
	str2 = ft_strtrim(str);
    printf("%s\n", str2);
    return (0);
}
