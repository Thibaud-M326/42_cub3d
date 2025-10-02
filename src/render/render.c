/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/02 16:43:22 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	**create_map(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = malloc(sizeof(int *) * 10);
	if (!map)
		return (NULL);
	while (i < 10)
	{
		map[i] = malloc(sizeof(int) * 10);
		if (!map[i])
		{
			while (--i >= 0)
			{
				free(map[i]);
				return (NULL);
			}
		}
		i++;
	}
	int temp_map[10][10] = {
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 1, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = temp_map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

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

int	player_print(t_data *data, t_player *player)
{
	put_one_pixel(data, player->pos_x, player->pos_y, 0xFF0000);
	put_one_pixel(data, player->pos_x + 1, player->pos_y + 1, 0xFF0000);
	put_one_pixel(data, player->pos_x + 1, player->pos_y, 0xFF0000);
	put_one_pixel(data, player->pos_x, player->pos_y + 1, 0xFF0000);
	return (0);
}

int	draw_ray(t_data *data)
{
	int		pos_x;
	int		pos_y;
	double	dir_x;
	double	dir_y;
	double	ray_x;
	double	ray_y;
	int		ray_length;

	pos_x = data->player->pos_x;
	pos_y = data->player->pos_y;
	dir_x = data->player->dir_x;
	dir_y = data->player->dir_y;
	ray_x = 0;
	ray_y = 0;
	ray_length = 200;
	while (ray_length)
	{
		put_one_pixel(data, pos_x + ray_x, pos_y + ray_y, 0x00FF00);
		ray_x += dir_x;
		ray_y += dir_y;
		ray_length--;
	}
	return (1);
}

int	render(t_data *data)
{
	int			x;
	int			y;
	int			**map;
	int			wall_color;
	int			floor_color;

	x = 0;
	y = 0;
	map = create_map();
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

	player_print(data, data->player);
	draw_ray(data);

	mlx_put_image_to_window(data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr, data->mlx_data->mlx_img->img_ptr, 0, 0);
	return (0);
}
