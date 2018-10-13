/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:14:44 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 12:35:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	wordcount(char const *s, char c)
{
	int i;
	int words;
	int isword;

	i = 0;
	isword = 0;
	if (s[0] != c)
		words = 1;
	else
		words = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			isword = 1;
		}
		if (s[i] == c && s[i])
		{
			words += (isword == 1) ? 1 : 0;
			isword = 0;
			i++;
		}
	}
	return (words);
}
static int wordl(const char *str, char c, int i)
{
	int counter;

	counter = 0;
	while (str[i] != c)
	{
		counter++;
		i++;
	}
	return (counter);
}

char	**ft_strsplit(char const *s, char c)
{
	char **temp;
	int i;
	int j;
	int x;

	i = 0;
	j = 0;
	if ((temp = (char **)malloc(sizeof(*temp) * \
		wordcount(s, c) + 1)) == NULL)
		return(0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			x = 0;
			if ((temp[j] = malloc(sizeof(char) * wordl(s, c, i) + 1)) == NULL)
				return (NULL);
			while (s[i] != c && s[i])
				temp[j][x++] = s[i++];
			temp[j++][x] = '\0';
		}
	}
	temp[j] = NULL;
	return (temp);
}

int main(void)
{
	char **str;
	int i;
	i = 0;
	str = ft_strsplit("*hello*fellow***students*", '*');
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
	return (0);
}
