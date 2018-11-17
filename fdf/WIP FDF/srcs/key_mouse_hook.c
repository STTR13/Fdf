/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:24:03 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/11/17 16:24:05 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>
int deal_key(int key, twin_list *window)
{
    if (key == 13)
        ft_putchar('W');
    else if (key == 0)
        ft_putchar('A');
    else if (key == 1)
        ft_putchar('S');
    else if (key == 2)
        ft_putchar('D');
    else if (key == 78)
        ft_putchar('-');
    else if (key == 69)
        ft_putchar('+');
    else if (key == 126)
        ft_putstr("Up Arrow");
    else if (key == 125)
        ft_putstr("Down Arrow");
    else if (key == 123)
        ft_putstr("Left Arrow");
    else if (key == 124)
        ft_putstr("Right Arrow");
    else if (key == 4)
        ft_putchar('H');
    else if (key == 53)
        exit(0);
    return (0);
}

int mouse_key(int key, twin_list *window)
{
    if (key == 1)
        ft_putstr("Left Button");
    if (key == 2)
        ft_putstr("Right Button");
    if (key == 3)
        ft_putstr("Middle Button");
    if (key == 4)
        ft_putstr("Scroll Up");
    if (key == 5)
        ft_putstr("Scroll Down");
    return (0);
}
