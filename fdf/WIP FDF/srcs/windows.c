#include "../includes/fdf.h"

void window_help(twin_list *whelp)
{
  if (whelp->helpscr  = 0)
  {
    whelp->helpscr = 1;
    whelp->mlx_ptr = mlx_init();
    whelp->win_ptr = mlx_new_window(whelp->mlx_ptr, 1000, 1000, "Help")
    mlx_key_hook(whelp->win_ptr, deal_key, window);
    mlx_loop(whelp->mlx_ptr);
  }
  else
    mlx_destroy_window(whelp->mlx_ptr, whelp->win_ptr);
}

void window_init(twin_list *window)
{
  window->helpscr = 0;
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, 1000, 1000, "FDF");
	mlx_key_hook(window->win_ptr, deal_key, window);
	mlx_mouse_hook(window->win_ptr, mouse_key, window);
	mlx_loop(window->mlx_ptr);
}
