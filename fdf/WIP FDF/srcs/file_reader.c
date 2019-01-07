#include "../includes/fdf.h"

int validinput(char *temp)
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

int **filecreator(char *temp, int lines, int linelen)
{
	int **input;
	int i;
	int j;
	int x;
	int tempnb;

	i = 0;
	input = ft_memalloc(sizeof(int **) * lines);
	while (i < lines)
	{
		input[i] = ft_memalloc(sizeof(int) * linelen);
		i++;
	}
	i = 0;
	j = 0;
	while (temp[x] != '\0')
	{
		if (temp[x] == '-' || ft_isdigit(temp[x]) == 1)
		{
			printf("TEST1\n");
			tempnb = ft_atoi(&temp[x]);
			if (j < linelen)
			{
				input[i][j] = tempnb;
				j++;
				printf("TEST2 j = %i\n", j);
			}
			else
			{
				i++;
				j = 0;
				input[i][j] = tempnb;
				j++;
				printf("TEST3 i = %i\n", i);
			}
			while (ft_isdigit(temp[x]) && temp[x + 1] != '\0')
			{
				printf("TEST4\n");
				x++;
			}
		}
		x++;
	}
	printf("TEST5\n");
	return(input);
}

int linecounter(char *str)
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

tinput *input_reader(tinput *lst, int fd)
{
	char *buffer;
	int counter;
	int ret;
	char *temp;

	counter = 1;
	if ((buffer = ft_strnew(counter + 1)) == NULL)
		return (NULL);
	if ((temp = ft_strnew(counter + 1)) == NULL)
		return (NULL);
	while ((ret = read(fd, buffer, counter)) > 0)
	{
		temp = ft_strjoin(temp, buffer);
		free(buffer);
		counter++;
		buffer = ft_strnew(counter + 1);
	}
	free(buffer);
	lst->lines = validinput(temp);
	lst->linelen = linecounter(temp);
	lst->input = filecreator(temp, lst->lines, lst->linelen);
	free(temp);
	return (lst);
}

tinput	*file_reader(int fd)
{
	tinput *lst;

	if (fd == -1)
		return (NULL);
	if ((lst = (tinput *)ft_memalloc(sizeof(tinput))) == NULL)
	{
		close (fd);
		return (NULL);
	}
	lst = input_reader(lst, fd);
	close (fd);
	return (lst);
}
