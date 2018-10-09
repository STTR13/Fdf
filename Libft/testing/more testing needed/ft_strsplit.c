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
char	**ft_strsplit(char const *s, char c)
{
	char *temp;
	while (s[i]
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
