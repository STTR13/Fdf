/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 14:06:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 13:08:47 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *temp;
	int i;

	i = 0;
	temp = str;
	while (n--)
	{
		temp[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

int main(void)
{
	char str[50];
	
	ft_strcpy(str, "dit is een test");
    ft_memset(str, '%', 10);
	ft_putstr(str);
	return(0);
}
