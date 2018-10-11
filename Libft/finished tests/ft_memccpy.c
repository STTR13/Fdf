/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:22:06 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/06 11:44:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *str1, const void *str2, int c, size_t n)
{
	int i;
	unsigned char *temp;
	unsigned char *temp2;
	
	i = 0;
	temp = (unsigned char *) str1;
	temp2 = (unsigned char *) str2;
	while (n-- && temp2[i] != '\0' && temp2[i] != c)
	{
        temp[i] = temp2[i];
        i++;
	}
    temp[i] = '\0';
    if (temp2[i] == c)
        return (str1);
    else
        return (NULL);
}

int main(void)
{
	char str[50], str2[50];
	
	ft_strcpy(str, "dit is een test");
	ft_memccpy(str2, str, 'a', 100);
	ft_putstr(str2);
	return (0);
}
