/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 16:57:27 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <math.h>

int	draw_vert_ceiling(t_data *data, int wall_start, int x)
{
	int	y;

	y = 0;
	while (y < wall_start)
	{
		put_one_pixel(data, x, y, data->textures->ceil_color);
		y++;
	}
	return (1);
}

int	draw_vert_floor(t_data *data, int wall_end, int x)
{
	while (wall_end < data->mlx_data->mlx_img->height)
	{
		put_one_pixel(data, x, wall_end, data->textures->floor_color);
		wall_end++;
	}
	return (1);
}

int	draw_vert_texture(t_data *data, int win_x, int tex_x, t_mlx_img *tex)
{
	int	color;
	int	wall_start;
	int	wall_end;
	int	wall_height;
	int	win_height;

	wall_start = data->textures->wall_start;
	wall_end = data->textures->wall_end;
	wall_height = wall_end - wall_start;
	win_height = data->mlx_data->mlx_img->height;
	draw_vert_ceiling(data, wall_start, win_x);
	while (wall_start < wall_end)
	{
		if (wall_start >= 0 && wall_start < win_height)
		{
			color = get_texture_color(data, tex, wall_start, tex_x);
			put_one_pixel(data, win_x, wall_start, color);
		}
		wall_start++;
	}
	draw_vert_floor(data, wall_end, win_x);
	return (1);
}

int	draw_textures(t_data *data, int win_x)
{
	t_mlx_img	*tex;
	int			wall_h;
	double		tex_x;
	int			win_h;

	ray_hit_point(data);
	tex_x = get_tex_x(data, &tex);
	win_h = data->mlx_data->mlx_img->height;
	wall_h = win_h / data->player->ray.distance;
	data->textures->wall_start = -wall_h / 2 + win_h / 2;
	data->textures->wall_end = wall_h / 2 + win_h / 2;
	draw_vert_texture(data, win_x, tex_x, tex);
	return (1);
}
