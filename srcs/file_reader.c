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
	while (str[j] != '\n')
		j++;
	while (str[i] != '\n' && i < j)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while (ft_isdigit(str[i]) == 1)
				i++;
			counter++;
		}
		i++;
	}
	return (counter);
}

static int		totallines(char *temp)
{
	int i;
	int lines;

	i = 0;
	lines = 1;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n' && temp[i + 1] != '\0')
			lines++;
		i++;
	}
	return (lines);
}

static int		**filefiller(int **input, char *temp, t_input *lst, int x)
{
	int i;
	int j;
	int tempnb;

	i = 0;
	j = -1;
	while (temp[x])
	{
		if (temp[x] == '-' || ft_isdigit(temp[x]) == 1)
		{
			tempnb = ft_atoi(&temp[x]);
			if (++j < lst->linelen)
				input[i][j] = tempnb;
			else if (j >= lst->linelen && i++ < lst->lines)
			{
				j = 0;
				input[i][j] = tempnb;
			}
			while ((temp[x] == '-' || ft_isdigit(temp[x])) && temp[x])
				x++;
		}
		x++;
	}
	return (input);
}

static int		**filecreator(char *temp, t_input *lst)
{
	int **input;
	int i;

	i = 0;
	input = ft_memalloc(sizeof(int *) * lst->lines);
	while (i < lst->lines)
	{
		input[i] = ft_memalloc(sizeof(int) * lst->linelen);
		i++;
	}
	i = 0;
	input = filefiller(input, temp, lst, i);
	return (input);
}

t_input			*file_reader(int fd)
{
	char	*line;
	char	*str;
	t_input	*lst;

	if (!(lst = ft_memalloc(sizeof(t_input))))
		return (NULL);
	if (!(str = ft_strnew(0)))
		return (NULL);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strjoinn(str, line);
		free(line);
	}
	close(fd);
	lst->lines = totallines(str);
	lst->linelen = linelen(str);
	lst->input = filecreator(str, lst);
	return (lst);
}
