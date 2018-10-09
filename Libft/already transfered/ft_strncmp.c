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
	int i;

	i = 0;
	while (i < n && str1[i] == str2[i] && str1[i] && str2[i])
		i++;
	return (str1[i] - str2[i]);
}
int main(void)
{
    char *test, *test2;
    
    test2 = "dit is een tast";
    test = "dit is een test";
    
    printf("%i", ft_strncmp(test, test2, 15));
}
