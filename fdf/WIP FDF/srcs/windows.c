#include "../includes/fdf.h"

int key_press(int key, void *param)
{
	(void)param;
	if (key == 13)
        ft_putchar('W');
    else if (key == 0)
        ft_putchar('A');
    else if (key == 1)
        ft_putchar('S');
    else if (key == 2)
        ft_putchar('D');
    else if (key == 78)
        ft_putchar('-');
    else if (key == 69)
        ft_putchar('+');
    else if (key == 126)
        ft_putstr("Up Arrow");
    else if (key == 125)
        ft_putstr("Down Arrow");
    else if (key == 123)
        ft_putstr("Left Arrow");
    else if (key == 124)
        ft_putstr("Right Arrow");
    else if (key == 4)
        ft_putchar('H');
    else if (key == 53)
		exit(0);
    return (0);
}

int mouse_press(int button, int x, int y, void *param)
{
	(void)param;
    if (button == 1)
        ft_putstr("Left Button");
    if (button == 2)
        ft_putstr("Right Button");
    if (button == 3)
        ft_putstr("Middle Button");
    if (button == 4)
        ft_putstr("Scroll Up");
    if (button == 5)
        ft_putstr("Scroll Down");
    return (0);
}

int mouse_move(int x, int y, void *param)
{
	(void)param;
	ft_putstr("moving");
	return(0);
}

int closewindow(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void window_init(twlist *window)
{
	void *param;
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
	//mlx_key_hook(window->win_ptr, deal_key, window);
	//mlx_mouse_hook(window->win_ptr, mouse_key, window);
	printf("\ntest\n");
	mlx_hook(window->win_ptr, 2, (1L << 0), key_press, window);
	mlx_hook(window->win_ptr, 4, (1L << 2), mouse_press, window);
	mlx_hook(window->win_ptr, 6, (1L << 13), mouse_move, window);
	mlx_hook(window->win_ptr, 17, (1L << 17), closewindow, window);
	mlx_loop(window->mlx_ptr);
}
