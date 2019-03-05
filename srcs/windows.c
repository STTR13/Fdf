#include "../includes/fdf.h"

void window_init(twlist *window)
{
	void *param;
	ve *vector;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WWIDTH, WHEIGHT, "FDF");
	int x = 0;
	int y = 0;
	int pos;
	int pos2 = 10;
	if (window->lst != NULL)
	{
		while (window->lst != NULL)
		{
			vector = window->lst->content;
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, (int)vector->x * 10, (int)vector->y * 10, COLORWHITE);
			window->lst = window->lst->next;
		}
	}
	mlx_hook(window->win_ptr, 2, (1L << 0), deal_key, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_key, window);
	mlx_hook(window->win_ptr, 6, (1L << 13), mouse_move, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), windowclose, window);
	mlx_loop(window->mlx_ptr);
}
