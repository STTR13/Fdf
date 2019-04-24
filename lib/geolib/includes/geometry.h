/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:59:05 by staeter           #+#    #+#             */
/*   Updated: 2019/02/28 12:59:06 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEOMETRY_H
# define GEOMETRY_H

# include <math.h>

typedef enum {
	false = 0,
	true = 1
}	t_bool;

typedef struct	s_matrix
{
	double		ai;
	double		aj;
	double		ak;
	double		bi;
	double		bj;
	double		bk;
	double		ci;
	double		cj;
	double		ck;
}				t_matrix;

typedef struct	s_ve
{
	double		x;
	double		y;
	double		z;
}				t_ve;

typedef struct	s_pl
{
	t_ve		p;
	t_ve		l;
	t_ve		m;
	t_ve		n;
}				t_pl;

/*
** --- Matrix ---
*/

t_matrix		*identity(t_matrix *ret);
t_matrix		*rot(t_ve *rot_axis, double angle, t_matrix *ret);

t_matrix		*adj(t_matrix *m, t_matrix *ret);
double			det(t_matrix *m);
t_matrix		*inv(t_matrix *m, t_matrix *ret);

t_ve			*dot_mv(t_matrix *m, t_ve v, t_ve *ret);
t_matrix		*scal_m(t_matrix *m, double s, t_matrix *ret);

/*
** --- Vector ---
*/

t_ve			*nullvector(t_ve *ret);
t_ve			*i(t_ve *ret);
t_ve			*j(t_ve *ret);
t_ve			*k(t_ve *ret);
t_ve			*set_ve(double z, double x, double y, t_ve *ret);

t_ve			*unit(t_ve *v, t_ve *ret);
double			norm(t_ve *v);

t_ve			*minus(t_ve *a, t_ve *b, t_ve *ret);
t_ve			*plus(t_ve *a, t_ve *b, t_ve *ret);

t_ve			*cross(t_ve *a, t_ve *b, t_ve *ret);
double			dot_vv(t_ve *a, t_ve *b);
t_ve			*scal_v(t_ve *v, double s, t_ve *ret);

t_ve			*rot_v(t_matrix *rot_matrix, t_ve *rot_center, t_ve *coord);

t_bool			isnullvector(t_ve *v);
t_bool			equal_v(t_ve *a, t_ve *b);
t_bool			equal_x_y(t_ve *a, t_ve *b);

/*
** --- Plan ---
*/

t_pl			*originsystem(t_pl *ret);

void			set_lm(t_pl *p, t_bool toward_origin);
t_matrix		*system_lmn_matrix(t_pl *plan, t_matrix *ret);

t_pl			*rot_p(t_matrix *rot_matrix, t_ve *rot_center, t_pl *plan);

#endif
