/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:49:04 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 12:55:59 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

int main(void)
{
	char *str = "test";
	ft_putendl_fd(str, -1);
	ft_putendl_fd(str, 0);
	ft_putendl_fd(str, 1);
	ft_putendl_fd(str, 2);
	ft_putendl_fd(str, 3);
	return (0);
}
