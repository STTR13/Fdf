/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:43:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 12:48:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

int main(void)
{
	ft_putstr_fd("test\n", -1);
	ft_putstr_fd("test\n", 0);
	ft_putstr_fd("test\n", 1);
	ft_putstr_fd("test\n", 2);
	ft_putstr_fd("test\n", 3);
	return (0);
}
