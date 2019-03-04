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

typedef enum {false=0, true=1} bool;

/*
** --- Vector ---
*/

typedef struct			s_ve
{
	bool	origin_fixed;
	double	x;
	double	y;
	double	z;
}						ve; //(n)

ve						unit(ve v);
double 					norm(ve v);

ve						minus(ve a, ve b);
ve						plus(ve a, ve b);

ve 						cross(ve a, ve b);
double 					dot(ve a, ve b);

ve						rot_x(ve v, double angle);
ve						rot_y(ve v, double angle);
ve						rot_z(ve v, double angle);
ve						rot(ve rotation_axis, ve v, double angle);

/*
** --- Plan ---
*/

typedef struct			s_pl
{
	ve		n;
	pt		p;
}						pl; //(n)

double					d(pl p);

ve						ortho_projection(ve point, pl plan);
ve						conic_projection(ve point, pl plan, ve eye);

/*
** --- Line ---
*/

typedef struct			s_li
{
	ve		n;
	pt		p;
}						li;

ve						inter(pl p, li l);

typedef double[3][3]	matrix;

#endif
