#include "modeling.h"

static edge		*edgeput_obj(edge *e, vertex *v, char *line)
{
	int	i;
	int	temp1;
	int	temp2;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]))
		{
			temp1 = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			while (!(ft_isdigit(line[i])))
				i++;
			temp2 = ft_atoi(&line[i]);
			while (ft_isdigit(line[i]))
				i++;
			if (!(e = add_edge(e, find_vertex_pos(v, temp1),\
			find_vertex_pos(v, temp1))))
				return (NULL);
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
