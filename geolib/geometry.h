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

/*
** --- Vector ---
*/

typedef struct	s_ve
{
	double	x;
	double	y;
	double	z;
}				ve; //(n)

ve				nullvector(void);
ve				i(void);
ve				j(void);
ve				k(void);

ve				unit(ve v);
double 			norm(ve v);

ve				minus(ve a, ve b);
ve				plus(ve a, ve b);

ve 				cross(ve a, ve b);
double 			dot_vv(ve a, ve b);
ve				scal_v(ve v, double s);

ve				rot_ve(ve rot_axis, ve v, double angle);

bool			isnullvector(ve v);

typedef enum {false=0, true=1} bool;

/*
** --- Matrix ---
*/

typedef double matrix[3][3];

matrix			I(void);
matrix			rot(ve rot_axis, double angle);

matrix			adj(matrix M);
double			det(matrix M);
matrix			inv(matrix M);

ve				dot_mv(matrix M, ve v);
matrix			scal_m(matrix M, double s);

/*
** --- Plan ---
*/

typedef struct	s_pl
{
	ve		p;
	ve		l;
	ve		m;
	ve		n;
}				pl; //(n)

void			set_lm(pl *p, bool toward_origin);
ve				to_lmn(ve point, pl plan);

ve				rot_pl(ve rot_axis, ve rot_center, pl p, double angle);

ve				ortho_projection(ve point, pl plan);
ve				conic_projection(ve point, pl plan, ve eye);

#endif
