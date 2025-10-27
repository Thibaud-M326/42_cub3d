/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:09:54 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:16:48 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

int	draw_ceiling(t_data *data, int wall_start, int x)
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

int	draw_wall(t_data *data, t_mlx_img *tex, int tex_x, int win_x)
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
	while (wall_start < wall_end)
	{
		if (wall_start >= 0 && wall_start < win_height)
		{
			color = get_texture_color(data, tex, tex_x, wall_start);
			put_one_pixel(data, win_x, wall_start, color);
		}
		wall_start++;
	}
	return (1);
}

int	draw_floor(t_data *data, int wall_end, int x)
{
	while (wall_end < data->mlx_data->mlx_img->height)
	{
		put_one_pixel(data, x, wall_end, data->textures->floor_color);
		wall_end++;
	}
	return (1);
}

int	draw_texture(t_data *data, t_mlx_img *tex, int tex_x, int win_x)
{
	int	wall_start;
	int	wall_end;
	int	wall_height;
	int	win_height;

	wall_start = data->textures->wall_start;
	wall_end = data->textures->wall_end;
	wall_height = wall_end - wall_start;
	win_height = data->mlx_data->mlx_img->height;
	draw_ceiling(data, wall_start, win_x);
	draw_wall(data, tex, tex_x, win_x);
	draw_floor(data, wall_end, win_x);
	return (1);
}
