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

int	wordcount(char const *s, char c)
{
	int i;
	int words;
	int isword;

	i = 0;
	words = 0;
	if (s[0] != c)
		isword = 1;
	else
		isword = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && isword == 1)
			words += 1;


		i++;
	}
}
char	**ft_strsplit(char const *s, char c)
{
	char **temp;
	int i;
	int words;

	i = 0;
	words = wordcount(s, c);
	temp = ft_strnew(s);
	return(0);
}

int main(void)
{
	char **str;

	str = ft_strsplit("*hello*fellow***students*", '*');
	//printf("%s", ft_strsplit("*hello*fellow***students*", '*'));
	printf("%s", *str);
	return (0);
}
