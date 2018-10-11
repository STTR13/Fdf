/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 10:26:23 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/06 10:36:19 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char *temp;
	int i;

	i = 0;
	temp = str;
	while (n-- && temp[i] != '\0')
	{
		temp[i] = '\0';
		i++;
	}
}

int main(void)
{
	char str[50];

	ft_strcpy(str, "dit is een test");
	ft_putstr(str);
	ft_putchar('\n');
	ft_bzero(str, 500);
	ft_putstr(str);
	ft_putchar('\n');
	return (0);
}
