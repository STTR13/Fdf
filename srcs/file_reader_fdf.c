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

#include "fdf.h"

/*
** These functions will read the file that has been sent with the
** executable. The information will be stored in a structure named
** t_input, which mallocs a char**.
*/

static t_bool	is_valid_linelen(char *str, int *line_len, int *line_count)
{
	int i;
	int counter;
	int j;

	*line_count += 1;
	i = 0;
	j = 0;
	counter = 0;
	while (str[j] != '\n' && str[j] != '\0')
		j++;
	while ((str[i] != '\n' && str[i] != '\0') && i < j)
	{
		if (ft_isdigit(str[i]) == 1)
		{
			while ((ft_isalnum(str[i]) == 1 || str[i] == ',') && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
				i++;
			counter++;
		}
		i++;
	}
	if (*line_len == -1)
		*line_len = counter;
	if (str[i] == '\0')
		return (true);
	if (counter != *line_len)
		return (false);
	return (is_valid_linelen(&str[i], line_len, line_count));
}

static char		*strfiller(char *str, int i)
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
		while (str[x] == ' ' && str[x] != '\0')
			x++;
		while ((ft_isalnum(str[x]) == 1 || str[x] == ',') && str[x] != '\0')
		{
			i++;
			x++;
		}
		if (str[x] == ' ' || str[x] == '\n')
		{
			if (!(input[pos] = strfiller(&str[x - i], i)))
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
	input = filefiller(input, temp, i);
	return (input);
}

t_input			*file_reader_fdf(int fd)
{
	char	*line;
	t_input	*lst;

	if (fd == -1 || (!(lst = ft_memalloc(sizeof(t_input))))) /* ||\
	(!(lst->str = ft_strnew(OPEN_MAX))))*/
		return (NULL);
	lst->linelen = -1;
	lst->lines = 0;
	if (!(lst->str = reader(fd)))
		return (NULL);
	close(fd);
	if (!is_valid_linelen(lst->str, &lst->linelen, &lst->lines))
	{
		ft_strdel(&lst->str);
		return (NULL);
	}
	/*while (get_next_line(fd, &line) == 1)
	{
		lst->str = ft_strjoinn(lst->str, line);
		if (lst->lines == 0)
			lst->linelen = linelen(lst->str);
		if (linelen(line) != lst->linelen)
		{
			free(line);
			return (NULL);
		}
		lst->lines += 1;
		free(line);
	}*/
	if (!(lst->input = filecreator(lst->str, lst)))
		return (NULL);
	ft_strdel(&lst->str);
	return (lst);
}
