/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:24:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 14:30:04 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
int		ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return ((unsigned char)str1[1] - (unsigned char)str2[1]);
	while (--n && *str1 == *str2 && *str1 && *str2)
	{
			str1++;
			str2++;
		}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}
int main(void)
{
    char *test, *test2;

    test2 = "qa";
    test = "a";

    printf("%i", ft_strncmp(test2, test, 0));
}
