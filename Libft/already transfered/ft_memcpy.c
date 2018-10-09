/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:40:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/06 11:20:56 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *str1, const void *str2, size_t n)
{
	int i;
	unsigned char *temp;
	unsigned char *temp2;
	
	i = 0;
	temp = (unsigned char *) str1;
	temp2 = (unsigned char *) str2;
	while (n-- && temp2[i] != '\0')
	{
		temp[i] = temp2[i];
		i++;
	}
    temp[i] = '\0';
	return (str1);
}

int main(void)
{
	char str[50], str2[50];

	ft_strcpy(str, "dit is een test");
	ft_memcpy(str2, str1, 100);
	ft_putstr(str2);
	return (0);
}
