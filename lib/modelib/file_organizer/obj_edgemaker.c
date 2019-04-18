#include "modeling.h"

static edge		*edgeput_obj(edge *e, vertex *v, char *line)
{
	int	i;
	int	temp1;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			while (line[i] != ' ')
			{
				temp1 = i;
				while (ft_isdigit(line[i]))
					i++;
				if ((line[i] == '/' || line[i] == ' ') && ft_isdigit(line[i + 1]))
				{
					if (!(e = add_edge(e, find_vertex_pos(v, ft_atoi(&line[temp1])),\
					find_vertex_pos(v, ft_atoi(&line[i + 1])))))
					return (NULL);
				}
				i++;
			}
		}
		if (line[i] != '\0')
			i++;
	}
	return (e);
}

edge			*edgefiller_obj(int fd, vertex *v)
{
	char	*line;
	edge	*e;

	if (fd == -1)
		return (NULL);
	e = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (line[0] == 'f')
		{
			if (!(e = edgeput_obj(e, v, line)))
				return (NULL);
		}
	}
	close(fd);
	return (e);
}
