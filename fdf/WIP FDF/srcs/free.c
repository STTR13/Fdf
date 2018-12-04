#include "../includes/fdf.h"

twlist *free_list(twlist *window)
{
	int i;

	i = 0;
	if (window != NULL)
	{
		while (window->file[i])
		{
			ft_strdel(&window->file[i]);
			i++;
		}
		ft_memdel(window->mlx_ptr);
		ft_memdel(window->win_ptr);
		window->color = 0;
	}
	return (window);
}
