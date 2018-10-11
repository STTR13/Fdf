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
	int j;
	int x;
  char	*str;

	i = 0;
	j = ft_strlen(s);
	x = 0;
	if (j == 0)
		return (NULL);
	while (s[i] != '\0' \
	&& (s[i] == ' ' || s[i] == ',' || s[i] == '\n' || s[i] == '\t'))
      i++;
	while ((s[j-1] == ' ' || s[j-1] == ',' || s[j-1] == '\n' || s[j-1] == '\t')\
	 && j-1 > 0)
			j--;
	str = ft_strnew(j - i);
	while (i < j)
	{
		str[x] = s[i];
		i++;
		x++;
	}
	str[x] = '\0';
	return (str);
}

int main(void)
{
	char *str, *str2;
    int i;
	//str = "   ,,,\n\n\n\t\t\t   dit is een test   ,,, \n\n\n\t\t\t\n";
	str = "dit is een test";
	str2 = ft_strtrim(str);
    printf("%s\n", str2);
    return (0);
}
