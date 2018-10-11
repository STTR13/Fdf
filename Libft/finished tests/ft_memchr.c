/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:09:13 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 10:27:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
void	*ft_memchr(const void *str, int c, size_t n)
{
	int				i;
	unsigned char	temp;
	unsigned char	*temp2;

	i = 0;
	temp2 = (unsigned char *)str;
    temp = (char)c;
	while (i < n)// && temp2[i] != '\0')
    {
        if (temp2[i] == temp)
            return (temp2 + i);
        i++;
    }
	return (NULL);
}
int main(void)
{
    char *str;
    
	str = "dit is een test";
    //ft_strcpy(str, "dit is een test.");
    //ft_memchr(str, 'a', 5);
    //ft_putstr(ft_memchr(str, 'a', 5));
	printf("%s", ft_memchr(str, 'a', 5));
	//ft_putstr(ft_memchr(str, 'a', 5));
    return (0);
}
