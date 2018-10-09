/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 14:22:20 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 15:07:28 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char		*ft_itoa(int n)
{
	int i;
	char *temp;

	i = n;
	if (i < 0)
	{
		i *= -1;
		temp += '-';
	}
	/*if (i >= 0 && i < 10)
		temp += i + '0';
	else if (i > 10)
	{
		ft_itoa(i / 10);
		temp += (i % 10) + '0';
	}*/
	return (temp);
}

int main(void)
{
	printf("%s", ft_itoa(230));
	printf("%c", '\n');
	printf("%s", ft_itoa(-230));
	return (0);
}
