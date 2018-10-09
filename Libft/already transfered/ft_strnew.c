/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:03:32 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/08 13:19:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
char	*ft_strnew(size_t size)
{
	void	*tmem;

	 tmem = malloc(size);
	 if (size == 0)
		 return (NULL);
	ft_memset(tmem, '\0', size);
	return (tmem);
}

int main(void)
{
	char *temp;

	temp = ft_strnew(10);
	printf("%s\n", temp);
	return(0);
}
