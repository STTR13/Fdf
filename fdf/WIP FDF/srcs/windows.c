#include "../includes/fdf.h"

void window_init(twlist *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 500, 500, "FDF");
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
			mlx_pixel_put(window->mlx_ptr, window->win_ptr, pos, pos2 + window->file->input[x][y], 255255255);
			pos += 10;
			y++;
		}
		pos2 += 10;
		x++;
	}
}
	mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_mouse_hook(window->win_ptr, mouse_key, window);
	mlx_loop(window->mlx_ptr);
}
