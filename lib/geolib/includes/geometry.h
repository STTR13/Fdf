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

#ifndef GEO_H
# define GEO_H

#include <math.h>

typedef enum {false=0, true=1} bool;

typedef struct	s_matrix
{
	double	ai;
	double	aj;
	double	ak;
	double	bi;
	double	bj;
	double	bk;
	double	ci;
	double	cj;
	double	ck;
}				matrix;

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

/*
** --- Matrix ---
*/

matrix			*I(matrix *ret);
matrix			*rot(ve *rot_axis, double angle, matrix *ret);

matrix			*adj(matrix *m, matrix *ret);
double			det(matrix *m);
matrix			*inv(matrix *m, matrix *ret);

ve				*dot_mv(matrix *m, ve v, ve *ret);
matrix			*scal_m(matrix *m, double s, matrix *ret);

/*
** --- Vector ---
*/

ve				*nullvector(ve *ret);
ve				*i(ve *ret);
ve				*j(ve *ret);
ve				*k(ve *ret);

ve				*unit(ve *v, ve *ret);
double 			norm(ve *v);

ve				*minus(ve *a, ve *b, ve *ret);
ve				*plus(ve *a, ve *b, ve *ret);

ve 				*cross(ve *a, ve *b, ve *ret);
double 			dot_vv(ve *a, ve *b);
ve				*scal_v(ve *v, double s, ve *ret);

ve				*rot_v(matrix *rot_matrix, ve *rot_center, ve *coord);

bool			isnullvector(ve *v);
bool			equal_v(ve *a, ve *b);
bool			equal_x_y(ve *a, ve *b);

/*
** --- Plan ---
*/

pl				*originsystem(pl *ret);

void			set_lm(pl *p, bool toward_origin);
matrix			*system_lmn_matrix(pl *plan, matrix *ret);

pl				*rot_p(matrix *rot_matrix, ve *rot_center, pl *plan);

#endif
