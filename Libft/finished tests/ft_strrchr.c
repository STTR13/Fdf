/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 11:34:30 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/05 11:40:54 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = ft_strlen((char *)str);
	while (str[i] != c && i > 0)
	{
		if (str[i] == c)
			return ((char *)str + i);
		i--;
	}
		return (NULL);
}

int main(void)
{
    char *str, str2, *str3;

    str = "abcd";
    str2 = 'd';
    str3 = ft_strrchr(str, 'a');
    printf("%s", str3);
    return (0);
}
