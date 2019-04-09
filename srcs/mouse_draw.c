#include "../includes/fdf.h"

void mouse_draw_line(void *window, int x, int y)
{
	static int coord[2][2];

	//set_pxl_img(((t_wlist*)(window))->w, x, y, 255);
	coord[0][0] = coord[1][0];
	coord[0][1] = coord[1][1];
	coord[1][0] = x;
	coord[1][1] = y;
	draw_line_img(((t_wlist*)(window))->w, coord);
	put_img(((t_wlist*)(window))->w);
}
