/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 14:49:56 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <math.h>

int	draw_vert_ceiling(t_data *data, int line_start, int x)
{
	int	y;

	y = 0;
	while (y < line_start)
	{
		put_one_pixel(data, x, y, data->textures->ceil_color);
		y++;
	}
	return (1);
}

int	draw_vert_floor(t_data *data, int line_end, int x)
{
	while (line_end < data->mlx_data->mlx_img->height)
	{
		put_one_pixel(data, x, line_end, data->textures->floor_color);
		line_end++;
	}
	return (1);
}

int	draw_vert_texture(t_data *data, int x, int tex_x, t_mlx_img *tex)
{
	int	color;
	int	cur_y;
	int	line_start;
	int	line_end;
	int	line_height;

	cur_y = data->textures->line_start;
	line_start = data->textures->line_start;
	line_end = data->textures->line_end;
	line_height = line_end - line_start;
	draw_vert_ceiling(data, line_start, x);
	while (cur_y < line_end)
	{
		if (cur_y >= 0 && cur_y < data->mlx_data->mlx_img->height)
		{
			color = get_texture_color(data, tex, cur_y, tex_x);
			put_one_pixel(data, x, cur_y, color);
		}
		cur_y++;
	}
	draw_vert_floor(data, line_end, x);
	return (1);
}

int	draw_textures(t_data *data, int x)
{
	t_mlx_img	*tex;
	int			line_h;
	double		tex_x;
	int			win_h;

	tex = NULL;
	ray_hit_point(data);
	tex_x = get_tex_x(data, &tex);
	win_h = data->mlx_data->mlx_img->height;
	line_h = win_h / data->player->ray.distance;
	data->textures->line_start = -line_h / 2 + win_h / 2;
	data->textures->line_end = line_h / 2 + win_h / 2;
	draw_vert_texture(data, x, tex_x, tex);
	return (1);
}
