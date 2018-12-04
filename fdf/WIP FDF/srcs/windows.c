#include "../includes/fdf.h"

void window_init(twlist *window)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 1000, 1000, "FDF");
	mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_mouse_hook(window->win_ptr, mouse_key, window);
	mlx_string_put(window-> mlx_ptr, window->win_ptr, 50, 50, 255, window->file);
	mlx_loop(window->mlx_ptr);
}
