/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:30:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/16 17:05:14 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int deal_key(int key, void *param)
{
	write(1, "X", 1);	
	return (0);
}

/*int close(int key, void *param)
{

}*/

int main()
{
	void *mlx_ptr;
	void *win_ptr;
	void *keypress;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 750, 500, "fdf");
	mlx_string_put(mlx_ptr, win_ptr, 10, 10, 255, "Test");
	mlx_key_hook(win_ptr, deal_key, (void *)0);
	mlx_mouse_hook(win_ptr, deal_key, (void *)0);
	mlx_loop(mlx_ptr);
}
