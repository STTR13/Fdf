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
static int	iswhitespace(char s)
{
	if (s == ' ' || s == ',' || s == '\n' || s == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		x;
	char	*str;

	i = 0;
	x = 0;
	if ((j = ft_strlen(s)) == 0 || s == NULL)
		return (NULL);
	while (s[i] != '\0' && iswhitespace(s[i]) == 1)
		i++;
	while (iswhitespace(s[j - 1]) == 1 && j - 1 > 0)
		j--;
	if ((str = ft_strnew(j - i)) == NULL)
		return (NULL);
	if (s[i] == '\0')
		return ((char *)s);
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
