#ifndef STRUCT_H
# define STRUCT_H

typedef enum {	false = 0, true = 1}
				bool;

typedef double	matrix[3][3];

typedef struct	s_ve
{
	double	x;
	double	y;
	double	z;
}				ve; //(n)

typedef struct	s_pl
{
	ve		p;
	ve		l;
	ve		m;
	ve		n;
}				pl; //(n)

typedef struct	s_drawing_list
{
	struct s_vertex			*vert;
	struct s_drawing_list	*next;
}				drawing_list; //(n)

typedef struct	s_event_hook
{
	int			(*key_press)(int keycode, void *param);
	int			(*key_release)(int keycode, void *param);
	int			(*mouse_press)(int button, int x, int y, void *param);
	int			(*mouse_release)(int button, int x, int y, void *param);
	int			(*mouse_move)(int x, int y, void *param);
	int			(*expose)(void *param);
	int			(*close)(void *param);
	void		*param;
}				event_hook;

typedef struct	s_image
{
	void 		*img_ptr;
	char		*data;
	int			bytes_per_pixel;
	int			size_line;
	int			edian; // 0 = litle edian | 1 = big edian
}				image;

typedef struct	s_window
{
	char		*name;
	int			width;
	int			height;
	void 		*mlx_ptr;
	void 		*win_ptr;
	image		*img;
	event_hook	hook;
}				window;

typedef struct	s_rgb
{
	unsigned short		r;
	unsigned short		g;
	unsigned short		b;
}				rgb; //(n) rename to t_rgb

typedef struct			s_input
{
	char	**input;
	int		lines;
	int		linelen;
}						t_input;

typedef struct			s_wlist
{
	t_input			*file;
	vertex			*v;
	drawing_list 	*dl;
	//event_hook		*eh;
	window			*w;
}						t_wlist;

#endif
