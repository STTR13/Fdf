/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:36:52 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 12:41:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int main(void)
{
	ft_putchar_fd('c', 0);
	ft_putchar_fd('\n', 0);
	ft_putchar_fd('c', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('c', 2);
	ft_putchar_fd('\n', 2);
	return(0);
}
