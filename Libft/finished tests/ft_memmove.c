/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:48:49 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 11:30:45 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	int i;
	unsigned char *tstr;
	unsigned char *tstr2;

	i = 0;
	tstr = (unsigned char *) str1;
	tstr2 = (unsigned char *) str2;
	if (tstr < tstr2)
		while (n--)
			*(tstr + n) = *(tstr2 + n);
	else
		while (i++ < n)
			*(tstr + i) = *(tstr2 + i);
	return (tstr);
}

int main(void)
{
	char str[17], str2[17];

	ft_strcpy(str, "oldstring");
	ft_strcpy(str2, "newstring");

	printf("Before memmove dest = %s, src = %s\n", str, str2);
	memmove(str+6, str2, 3);
	printf("After memmove dest = %s, src = %s\n", str, str2);
	return (0);
}
