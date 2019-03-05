/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 11:57:57 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/01/28 12:00:38 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		linelen(char *str)
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

int		totallines(char *temp)
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

int		**filefiller(int **input, char *temp, tinput *lst)
{
	int i;
	int j;
	int x;
	int tempnb;

	i = 0;
	j = -1;
	x = 0;
	while (temp[x])
	{

		if (temp[x] == '-' || ft_isdigit(temp[x]) == 1)
		{
			tempnb = ft_atoi(&temp[x]);
			if (++j < lst->linelen)
			{
				input[i][j] = tempnb;
				printf("%i\n", tempnb);
			}
			else
			{
				i++;
				j = 0;
				input[i][j] = tempnb;
				printf("%i\n", tempnb);
			}
			while ((temp[x] == '-' || ft_isdigit(temp[x])) \
					&& temp[x])
				x++;
		}
		x++;
	}
	return (input);
}

int		**filecreator(char *temp, tinput *lst)
{
	int **input;
	int i;

	i = 0;
	input = ft_memalloc(sizeof(int **) * lst->lines);
	while (i < lst->lines)
	{
		input[i] = ft_memalloc(sizeof(int) * lst->linelen);
		i++;
	}
	input = filefiller(input, temp, lst);
	return (input);
}

tinput	*file_reader(int fd)
{
	char *line;
	char *str;
	tinput *lst;

	str = "\0";
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		str = ft_strjoinn(str, line);
		free(line);
	}
	close(fd);
	printf("%s\n", str);
	printf("A\n");
	lst->lines = totallines(str);
	printf("B\n");
	lst->linelen = linelen(str);
	printf("C\n");
	printf("totallines: %i, linelen: %i\n", lst->lines, lst->linelen);
	lst->input = filecreator(str, lst);

	printf("%i", lst->input[5][5]);
	return (lst);
}
