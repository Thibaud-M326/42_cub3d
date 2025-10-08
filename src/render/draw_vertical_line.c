/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/08 19:37:30 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int draw_vert(t_data *data, int x, int line_start, int line_end, int color)
{
    while (line_start < line_end)
    {
        put_one_pixel(data, x, line_start, color);
        line_start++;
    }
    return (1);
}

//x c'est la colonne sur laquelle on va afficher le mur
//distance dans data represente la distance du mur
//on va devoir faire une fonction qui dessine une ligne verticalle
//
int draw_vertical_line(t_data *data, int x)
{
    t_ray   *ray;
    int     line_h;
    int     line_start;
    int     line_end;
    int     color;

    color = 0x3ED6D2;
    ray = &data->player->ray;
    line_h = 1000 / ray->distance;
    line_start = -line_h / 2 + 1000 / 2;
    if (line_start < 0)
        line_start = 0;
    line_end = line_h / 2 + 1000 / 2;
    if (line_end < 0)
        line_end = 1000 - 1;

    if (ray->side == 1)
        color /= 2;
    draw_vert(data, x, line_start, line_end, color);
    return (1);
}