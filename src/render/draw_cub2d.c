/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_cub2d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:12:12 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/09 16:58:51 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdlib.h>

int	render_box(t_data *data, int mapX, int mapY, int color)
{
	int	box_w;
	int	box_h;
	int	x;
	int	y;

	box_w = data->mlx_data->mlx_img->width / 10;
	box_h = data->mlx_data->mlx_img->height / 10;
	x = 0;
	y = 0;
	while (y < data->mlx_data->mlx_img->height)
	{
		x = 0;
		while (x < data->mlx_data->mlx_img->width)
		{
			if (x >= mapX * box_w && x <= mapX * box_w + box_w)
				if (y >= mapY * box_h && y <= mapY * box_h + box_h)
					put_one_pixel(data, x, y, color);
			if (x == mapX * box_w)
				put_one_pixel(data, x, y, 0xFFFFFF);
			if (y == mapY * box_h)
				put_one_pixel(data, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	return (0);
}

int free_map(t_map *map)
{
	int	y;
	
	y = 0;
	while (y < map->map_h)
	{
		free(map->map[y]);
		map->map[y] = NULL;
		y++;
	}
	free(map->map);
	map->map = NULL;
	free(map);
	map = NULL;
	return (1);
}

int draw_cub2d(t_data *data)
{
    int			x;
	int			y;
	int			**map;
	int			wall_color;
	int			floor_color;

	x = 0;
	y = 0;

	data->map->map_w = 10;
	data->map->map_h = 10;
	map = data->map->map;
	wall_color = mix_color(42, 44, 101);
	floor_color = mix_color(5, 3, 2);
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (map[y][x] == 1)
				render_box(data, x, y, wall_color);
			if (map[y][x] == 0)
				render_box(data, x, y, floor_color);
			x++;
		}
		y++;
	}

    // free_map(data->map); // faut pas free ? 
    return (1);
}