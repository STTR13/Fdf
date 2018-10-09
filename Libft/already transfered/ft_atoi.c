/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 15:17:07 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 10:29:01 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int digit;

	sign = 1;
	i = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '+'
			|| *str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\n')
	{
		digit = *str - '0';
		if (digit > 9 || digit < 0)
			break ;
		i = (i * 10) + digit;
		str++;
	}
	i *= sign;
	return (i);
}

int main(void)
{
	char *str;

	str = "-1561613";
	printf("%i", ft_atoi(str));
	return (0);
}
