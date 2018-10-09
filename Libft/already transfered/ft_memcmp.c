/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 11:36:50 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 12:04:49 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*tstr1;
	unsigned char	*tstr2;
	int				i;

	i = 0;
	tstr1 = (unsigned char *)str1;
	tstr2 = (unsigned char *)str2;
	while (i < n)
	{
		if (*(tstr1 + i) != *(tstr2 + i))
			return(tstr1[i] - tstr2[i]);
		i++;
	}
		return (0);
}

int main(void)
{
	char str[17], str2[17];
	
	ft_strcpy(str, "DIT IS EEN TEST");
	ft_strcpy(str2, "dit is een test");
	printf("%i", ft_memcmp(str+5, str2+2, 5));
	return (0);
}
