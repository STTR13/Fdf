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

ve				*rot_v(matrix *rot_matrix, ve *rot_center, ve *coord)
{
	ve t[2];

	*coord = *plus(
		rot_center,
		dot_mv(
			rot_matrix,
			*minus(coord, rot_center, &t[0]),
			&t[1]
		),
		&t[0]
	);
	return (coord);
}
