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

/*
** --- Matrix ---
*/

matrix			*I(matrix *ret);
matrix			*rot(ve rot_axis, double angle, matrix *ret);

matrix			*adj(matrix m, matrix *ret);
double			det(matrix m);
matrix			*inv(matrix m, matrix *ret);

ve				*dot_mv(matrix m, ve v, ve *ret);
matrix			*scal_m(matrix m, double s, matrix *ret);

/*
** --- Vector ---
*/

ve				*nullvector(ve *ret);
ve				*i(ve *ret);
ve				*j(ve *ret);
ve				*k(ve *ret);

ve				*unit(ve v, ve *ret);
double 			norm(ve v);

ve				*minus(ve a, ve b, ve *ret);
ve				*plus(ve a, ve b, ve *ret);

ve 				*cross(ve a, ve b, ve *ret);
double 			dot_vv(ve a, ve b);
ve				*scal_v(ve v, double s, ve *ret);

bool			isnullvector(ve v);
bool			equal_v(ve a, ve b);
void			copy_v(ve origin, ve *dest);

/*
** --- Plan ---
*/

void			set_lm(pl *p, bool toward_origin);
matrix			*system_lmn_matrix(pl plan, matrix *ret);

ve				*rot_pl(ve rot_axis, ve rot_center, pl p, double angle, matrix *ret);

ve				*ortho_projection(ve point, pl plan, ve *ret);
ve				*conic_projection(ve point, pl plan, ve eye, ve *ret);

#endif
