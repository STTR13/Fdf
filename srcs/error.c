#include "../includes/fdf.h"

void errormessage(int i, t_wlist *window)
{
	if (i == 1)
	{
		ft_putendl("usage: ./fdf input_file");
		exit (0);
	}
	else if (i == 2)
	{
		free_all(window);
		ft_putendl("error");
		exit (0);
	}
}
