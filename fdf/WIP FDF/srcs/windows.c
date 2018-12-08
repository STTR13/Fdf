#include "../includes/fdf.h"

void window_init(twlist *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 1000, 1000, "FDF");
	int x = 0;
	int y = 0;
	int pos = 50;
	int pos2 = 50;
	while (x < 100)
	{
		y = 0;
		pos = 50;
		while (y < 200)
		{
			if (window->file->file[x][y] != 0)
				mlx_pixel_put(window->mlx_ptr, window->win_ptr, pos, window->file->file[x][y]+pos2, 255);
			pos += 5;
			y++;
		}
		pos2 += 5;
		x++;
	}
	mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_mouse_hook(window->win_ptr, mouse_key, window);
	mlx_loop(window->mlx_ptr);
}
