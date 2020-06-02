/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/25 15:42:12 by staeter           #+#    #+#             */
/*   Updated: 2018/08/25 15:42:17 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** free *s1 allocate a memory containing the cast
** (NB: tion == two in one new)
*/

static int		strcat_tion(char **s1, int s1_len, char **s2, int s2_len)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (dest != NULL)
	{
		i = 0;
		while (i < s1_len)
		{
			dest[i] = (*s1)[i];
			i++;
		}
		j = 0;
		while (j < s2_len)
		{
			dest[i + j] = (*s2)[j];
			j++;
		}
		dest[i + j] = 0;
		free(*s1);
		*s1 = dest;
		return (0);
	}
	return (1);
}

char			*reader(int filedesc)
{
	int		a;
	int		b;
	char	*acc;
	char	*buf;

	a = 0;
	acc = malloc(sizeof(char));
	if (acc == NULL)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buf == NULL)
		return (NULL);
	acc[0] = '\0';
	buf[BUFF_SIZE] = '\0';
	while ((b = read(filedesc, buf, BUFF_SIZE)))
	{
		if (strcat_tion(&acc, a, &buf, b) || b == -1)
			return (NULL);
		a += b;
	}
	free(buf);
	acc[a] = 0;
	return (acc);
}
