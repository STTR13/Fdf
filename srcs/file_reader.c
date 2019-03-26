/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:57:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:48:07 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		linelen(char *str)
{
	int i;
	int counter;
	int j;

	i = 0;
	j = 0;
	counter = 0;
	while (str[j] != '\0')
		j++;
	while (str[i] != '\0' && i < j)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while ((ft_isalnum(str[i]) == 1 || str[i] == ',') && str[i] != ' ')
				i++;
			counter++;
		}
		i++;
	}
	return (counter);
}

static char		*charfiller(char *str, int i)
{
	char *temp;

	if (!(temp = ft_strnew(i)))
		return (NULL);
	temp = ft_strncpy(temp, str, i);
	return (temp);
}

static char		**filefiller(char **input, char *str, int x)
{
	int i;
	int pos;

	pos = 0;
	while (str[x] != '\0')
	{
		i = 0;
		while (str[x] == ' ')
			x++;
		while ((ft_isalnum(str[x]) == 1 || str[x] == ',') && str[x] != '\0')
		{
			i++;
			x++;
		}
		if ((str[x] == ' ' || str[x] == '\n') && str[x] != '\0')
		{
			if (!(input[pos] = charfiller(&str[x - i], i)))
				return (NULL);
			i = 0;
			pos++;
		}
		x++;
	}
	return (input);
}

static char		**filecreator(char *temp, t_input *lst)
{
	char	**input;
	int		i;

	i = 0;
	if (!(input = ft_memalloc(sizeof(char **) * \
	(lst->lines * lst->linelen + 1))))
		return (NULL);
	i = 0;
	input = filefiller(input, temp, i);
	return (input);
}

t_input			*file_reader(int fd)
{
	char	*line;
	char	*str;
	t_input	*lst;

	if (fd == -1 || (!(lst = ft_memalloc(sizeof(t_input)))) || \
	(!(str = ft_strnew(0))))
		return (NULL);
	lst->lines = 0;
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strjoinn(str, line);
		if (lst->lines == 0)
			lst->linelen = linelen(str);
		lst->lines += 1;
		free(line);
	}
	close(fd);
	if (!(lst->input = filecreator(str, lst)))
		return (NULL);
	ft_strdel(&str);
	return (lst);
}
