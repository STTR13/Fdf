/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 12:02:18 by staeter           #+#    #+#             */
/*   Updated: 2019/04/09 12:02:26 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometry.h"

t_ve		*rot_v(t_matrix *rot_matrix, t_ve *rot_center, t_ve *coord)
{
	t_ve t[2];

	*coord = *plus(
		rot_center,
		dot_mv(
			rot_matrix,
			*minus(coord, rot_center, &t[0]),
			&t[1]),
		&t[0]);
	return (coord);
}
