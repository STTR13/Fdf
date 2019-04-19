/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expose.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:57:13 by staeter           #+#    #+#             */
/*   Updated: 2019/04/18 17:57:14 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int		expose(void *window)
{
	//mlx_mouse_get_pos(???mlx_win_list_t *win???,
	//	((warehouse*)window)->mouse_last_pos[0],
	//	((warehouse*)window)->mouse_last_pos[1]);
	refresh_win((warehouse*)window);
	return (0);
}
