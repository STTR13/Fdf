/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:20:11 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/04 14:24:09 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = 0;
	if (str1 == NULL)
		return (3);
	while (*str1 == *str2 && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
