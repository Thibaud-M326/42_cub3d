/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_borders.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:18:08 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/15 01:23:50 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "minimap.h"
#include "mlx.h"

static void	draw_horizontal_borders(t_data *data)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;
	int	start_x;

	start_x = WIDTH / 30;
	end_x = WIDTH / 3.5;
	end_y = HEIGHT / 3.5;
	y = HEIGHT / 30;
	x = start_x;
	while (x < end_x)
	{
		put_one_pixel(data, x, y, BORDER_MMAP);
		x++;
	}
	x = start_x;
	y = end_y - 1;
	while (x < end_x)
	{
		put_one_pixel(data, x, y, BORDER_MMAP);
		x++;
	}
}

static void	draw_vertical_borders(t_data *data)
{
	int	x;
	int	y;
	int	end_x;
	int	end_y;
	int	start_y;

	start_y = HEIGHT / 30;
	end_x = WIDTH / 3.5;
	end_y = HEIGHT / 3.5;
	x = WIDTH / 30;
	y = start_y;
	while (y < end_y)
	{
		put_one_pixel(data, x, y, BORDER_MMAP);
		y++;
	}
	x = end_x - 1;
	y = start_y;
	while (y < end_y)
	{
		put_one_pixel(data, x, y, BORDER_MMAP);
		y++;
	}
}

void	calculate_scale(t_data *data)
{
	int	minimap_width;
	int	minimap_height;
	int	map_width;
	int	map_height;

	#include <stdio.h>
	minimap_width = (int)(WIDTH / 3.5) - (WIDTH / 30);
	printf("%d\n", minimap_width);
	minimap_height = (int)(HEIGHT / 3.5) - (HEIGHT / 30);
	printf("%d\n", minimap_height);
	map_width = data->map->width;
	map_height = data->map->height;
	if (map_width > 0)
		data->map->tile_width = minimap_width / map_width;
	else
		data->map->tile_width = 1;
	if (map_height > 0)
		data->map->tile_height = minimap_height / map_height;
	else
		data->map->tile_height = 1;
	printf("tile W = %d\n", data->map->tile_width);
	printf("tile H = %d\n", data->map->tile_height);

}

static void	draw_rectangle(t_data *data, int start_x, int start_y, int color)
{
	int	i;
	int	j;
	double	x;
	double	y;

	i = 0;
	x = start_x;
	y = start_y;
	while (i < data->map->height + 2)
	{
		j = 0;
		while (j < data->map->width)
		{
			put_one_pixel(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_background_borders(t_data *data)
{
	int	start_x;
	int	start_y;
	int	x;
	int	y;
	int	i;
	int	j;

	start_x = WIDTH / 30;
	start_y = HEIGHT / 30;
	calculate_scale(data);
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			x = (start_x + j) * data->map->tile_width;
			y = (start_y + i) * data->map->tile_height;
			if (data->map->map[i][j] == '1')
				draw_rectangle(data, x, y, WALLS_MMAP);
			else
				draw_rectangle(data, x, y, BACKGROUND_MMAP);
			j++;
		}
		i++;
	}
	draw_horizontal_borders(data);
	draw_vertical_borders(data);
}

// void	draw_background_borders(t_data *data)
// {
// 	int	x;
// 	int	y;
// 	int	i;
// 	int	j;

// 	y = HEIGHT / 30;
// 	i = 0;
// 	while (y < HEIGHT / 3.5 && data->map->map[i])
// 	{
// 		x = WIDTH / 30;
// 		j = 0;
// 		while (x < WIDTH / 3.5 && data->map->map[i][j])
// 		{
// 			if (data->map->map[i][j] == '1')
// 				put_one_pixel(data, x, y, WALLS_MMAP);
// 			else
// 				put_one_pixel(data, x, y, BACKGROUND_MMAP);
// 			x++;
// 		}
// 		y++;
// 	}
// draw_horizontal_borders(data);
// draw_vertical_borders(data);
// }
