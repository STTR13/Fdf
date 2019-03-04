#include "../includes/fdf.h"

void window_init(twlist *window)
{
	void *param;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, WWIDTH, WHEIGHT, "FDF");
	int x = 0;
	int y = 0;
	int pos;
	int pos2 = 10;
	if (window->file != NULL)
	{
		while (x < window->file->lines)
		{
			y = 0;
			pos = 10;
			while (y < window->file->linelen)
			{
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, pos, pos2 + window->file->input[x][y], COLORWHITE);
				pos += 10;
				y++;
			}
			pos2 += 10;
			x++;
		}
	}
	mlx_hook(window->win_ptr, 2, (1L << 0), deal_key, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_key, window);
	mlx_hook(window->win_ptr, 6, (1L << 13), mouse_move, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), windowclose, window);
	mlx_loop(window->mlx_ptr);
}
