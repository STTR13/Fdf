/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_grad.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:56:08 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/04/09 13:56:09 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int get_light(int start, int end, double percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

int get_color_grad(double percent, edge *e)
{
    int     red;
    int     green;
    int     blue;
    double  percentage;

    if (e->vert1->color == e->vert2->color)
        return (e->vert1->color);
    red = get_light((e->vert1->color >> 16) & 0xFF, (e->vert2->color >> 16) & 0xFF, percent);
    green = get_light((e->vert1->color >> 8) & 0xFF, (e->vert2->color >> 8) & 0xFF, percent);
    blue = get_light(e->vert1->color & 0xFF, e->vert2->color & 0xFF, percent);
    return ((red << 16) | (green << 8) | blue);
}
