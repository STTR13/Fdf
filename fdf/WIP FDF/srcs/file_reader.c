#include "../includes/fdf.h"

int validinput(char *temp)
{
	int i;
	int lines;

	i = 0;
	lines = 0;
	while (temp[i] != '\0')
	{
		if ((temp[i] == ' ' || temp[i] == '\n' || ft_isdigit(temp[i]) == 1))
		{
			if (temp[i] == '\n' && temp[i + 1] != '\0')
				lines++;
			i++;
		}
		else
			return (0);
	}
	return (lines);
}

int **filecreator(char *temp, int lines)
{
	int **input;
	int boolean;
	int numbers;
	int *totnumbers;
	int i;
	int j;
	int x = 0;
	int y = 0;
	boolean = 0;
	i = 0;
	j = 0;
	input = ft_memalloc(sizeof(int **) * lines + 1);
	totnumbers = ft_memalloc(sizeof(int *) * lines + 1);
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
		{
			input[j] = ft_memalloc(sizeof(int *) * numbers);
			j++;
			boolean = 0;
			totnumbers[x] = numbers;
			x++;
			numbers = 0;
		}
		else
		{
			if (ft_isdigit(temp[i]) == 1 && boolean == 0)
			{
				boolean = 1;
				numbers++;
			}
			else if (temp[i] == ' ' || temp[i] == '\n')
				boolean = 0;
		}
		i++;
	}
	i = 0;
	x = 0;
	y = 0;
	int tempn;
	while (temp[i] != '\0')
	{
		if (ft_isdigit(temp[i]) == 1)
		{
			tempn = ft_atoi(&temp[i]);
			if (y < totnumbers[x])
			{
				input[x][y] = tempn;
				y++;
			}
			else
			{
				x++;
				y = 0;
				input[x][y] = tempn;
				y++;
			}
			while (ft_isdigit(temp[i]))
				i++;
		}
		i++;
	}
	x = 0;
	y = 0;
	while (x < lines)
	{
		printf("%i\n", totnumbers[x]);
		x++;
	}
	return(input);
}

tinput *character_convertor(tinput *lst, char *temp)
{
	int i;
	int j;
	int lines;

	if ((lines = validinput(temp)) > 0)
	{
		lst->file = filecreator(temp, lines);
		return (lst);
	}
	return (NULL);

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
	lst = character_convertor(lst, temp);
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
