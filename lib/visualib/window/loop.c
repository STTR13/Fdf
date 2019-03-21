/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: staeter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:06:54 by staeter           #+#    #+#             */
/*   Updated: 2019/03/07 12:06:56 by staeter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual.h"

void			loop(window *w)
{
	if (!w)
		return ;
	if (w->hook.key_press)
		mlx_hook(w->mlx_ptr, 2, 0, w->hook.key_press, w->hook.param);
	if (w->hook.key_release)
		mlx_hook(w->mlx_ptr, 3, 0, w->hook.key_release, w->hook.param);
	if (w->hook.mouse_press)
		mlx_hook(w->mlx_ptr, 4, 0, w->hook.mouse_press, w->hook.param);
	if (w->hook.mouse_release)
		mlx_hook(w->mlx_ptr, 5, 0, w->hook.mouse_release, w->hook.param);
	if (w->hook.mouse_move)
		mlx_hook(w->mlx_ptr, 6, 0, w->hook.mouse_move, w->hook.param);
	if (w->hook.expose)
		mlx_hook(w->mlx_ptr, 12, 0, w->hook.expose, w->hook.param);
	if (w->hook.close)
		mlx_hook(w->mlx_ptr, 17, 0, w->hook.close, w->hook.param);
	mlx_loop(w->mlx_ptr);
}
