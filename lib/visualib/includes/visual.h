/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 19:08:08 by staeter           #+#    #+#             */
/*   Updated: 2019/03/05 19:08:09 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUAL_H
# define VISUAL_H

# include <math.h>
# include <stdlib.h>

# include "symlink_mlx.h"
# include "symlink_geolib_includes/geometry.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define BUTTONPRESS 4
# define BUTTONRELEASE 5
# define MOTIONNOTIFY 6
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
# define FOCUSIN 9
# define FOCUSOUT 10
# define KEYMAPNOTIFY 11
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
# define VISIBILITYNOTIFY 15
# define CREATENOTIFY 16
# define DESTROYNOTIFY 17
# define UNMAPNOTIFY 18
# define MAPNOTIFY 19
# define MAPREQUEST 20
# define REPARENTNOTIFY 21
# define CONFIGURENOTIFY 22
# define CONFIGUREREQUEST 23
# define GRAVITYNOTIFY 24

# define BUT1_KEY 1
# define BUT2_KEY 2
# define BUT3_KEY 3
# define SCROLLUP_KEY 4
# define SCROLLDOWN_KEY 5
# define SCROLLLEFT_KEY 6
# define SCROLLRIGHT_KEY 7

# define A_KEY 0
# define B_KEY 11
# define C_KEY 8
# define D_KEY 2
# define E_KEY 14
# define F_KEY 3
# define G_KEY 5
# define H_KEY 4
# define I_KEY 34
# define J_KEY 38
# define K_KEY 40
# define L_KEY 37
# define M_KEY 46
# define N_KEY 45
# define O_KEY 31
# define P_KEY 35
# define Q_KEY 12
# define R_KEY 15
# define S_KEY 1
# define T_KEY 17
# define U_KEY 32
# define V_KEY 9
# define W_KEY 13
# define X_KEY 7
# define Y_KEY 16
# define Z_KEY 6

# define F1_KEY 122
# define F2_KEY 120
# define F3_KEY 99
# define F4_KEY 118
# define F5_KEY 96
# define F6_KEY 97
# define F7_KEY 98
# define F8_KEY 100
# define F9_KEY 101
# define F10_KEY 109
# define F12_KEY 111
# define F13_KEY 105
# define F14_KEY 107
# define F15_KEY 113
# define F16_KEY 106
# define F17_KEY 64
# define F18_KEY 79
# define F19_KEY 80

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123

# define ESC_KEY 53
# define TAB_KEY 48
# define CL_KEY 272
# define LSFT_KEY 257
# define LCTRL_KEY 256
# define LOPT_KEY 261
# define LCMD_KEY 259
# define LDEL_KEY 51
# define RTN_KEY 36
# define RSFT_KEY 258
# define RCTRL_KEY 269
# define ROPT_KEY 262
# define RCMD_KEY 260
# define FN_KEY 279
# define RDEL_KEY 117
# define HOME_KEY 115
# define END_KEY 119
# define PUP_KEY 116
# define PDOWN_KEY 121
# define CLR_KEY 71

typedef struct	s_event_hook
{
	int			(*key_press)(int keycode, void *param);
	int			(*key_release)(int keycode, void *param);
	int			(*mouse_press)(int button, int x, int y, void *param);
	int			(*mouse_release)(int button, int x, int y, void *param);
	int			(*mouse_move)(int x, int y, void *param);
	int			(*expose)(void *param);
	int			(*close)(void *param);
	int			(*loop)(void *param);
	void		*param;
}				t_event_hook;

typedef struct	s_image
{
	void		*img_ptr;
	char		*data;
	int			bytes_per_pixel;
	int			size_line;
	int			edian;
}				t_image;

typedef struct	s_window
{
	char			*name;
	int				width;
	int				height;
	void			*mlx_ptr;
	void			*win_ptr;
	t_image			*img;
	t_event_hook	hook;
}				t_window;

/*
** --- Window ---
*/

t_window		*new_window(char *name, int width, int height);
void			free_window(t_window *w);

void			loop(t_window *w);

/*
** --- Image ---
*/

bool			new_img(t_window *w);
void			free_img(t_window *w);
bool			re_img(t_window *w);
bool			put_img(t_window *w);
int				line_grad(int c1, int c2, double current);

bool			set_pxl_img(t_window *w, int x, int y, int color);
bool			draw_line_img(t_window *w, int coord[2][2], int color[2]);

#endif
