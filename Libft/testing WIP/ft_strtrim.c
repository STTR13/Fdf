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
static int	iswhitespace(char *s, int *i, int *j)
{
	while ((s == ' ' || s == ',' || s == '\n' || s == '\t') && s[i] != '\0')
		i++;
	while ((s == ' ' || s == ',' || s == '\n' || s == '\t') && j > 0)
		j--;
	if (*i || *j < ft_strlen(s))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (!iswhitespace((char *)s, &i, &j) || !ft_strlen(s))
		return (char *)s);
	if ((char)s[0] == '\0')
		return ((char *)s);
	while (iswhitespace(s[j - 1]) == 1 && j - 1 > 0)
		j--;
	while (++i < j && iswhitespace(s[i]) == 1)
		j--;
	if (j <= 0)
		j = 0;
	if ((str = ft_strnew(j)) == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}

int main(void)
{
	char *str, *str2, *str3;
    int i;

	//str = "   ,,,\n\n\n\t\t\t   dit is een test   ,,, \n\n\n\t\t\t\n";
	str = "";
	str2 = ft_strtrim(str);
    printf("%s\n", str2);
    return (0);
}
