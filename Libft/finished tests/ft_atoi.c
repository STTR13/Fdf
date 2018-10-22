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
	size_t	i;
	int		sign;
	char	*temp;
	int		digit;

	sign = 1;
	i = 0;
	temp = (char *)str;
	while (*temp == ' ' || *temp == '\f' || *temp == '\n' /*|| *temp == '+'*/
			|| *temp == '\r' || *temp == '\t' || *temp == '\v')
		temp++;
	if (*temp == '-')
	{
		sign = -1;
		temp++;
	}
	while (*temp != '\n')
	{
		digit = *temp - '0';
		if (digit > 9 || digit < 0)
			break ;
		i = (i * 10) + digit;
		temp++;
	}
	return (i * sign);
}

int main(void)
{
	char *str;

	str = "++876";
	printf("%i", ft_strcmp(ft_atoi("++876"), atoi("++876"));
	return (0);
}
