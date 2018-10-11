/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 12:40:24 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 12:47:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
int		ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	else
		return (0);
}

int main(void)
{
	char *test, *test2;

	test2 = "dit is een test";
	test = "DIT IS EEN TEST";

	printf("%i", ft_strequ(test, test2));
}
