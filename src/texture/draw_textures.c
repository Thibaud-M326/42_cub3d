/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 17:15:22 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <math.h>

int	draw_vert_texture(t_data *data, int x, int tex_x, t_mlx_img *tex)
{
	int	color;
	int	current_y;
	int	line_start;
	int	line_end;

	current_y = data->textures->line_start;
	line_start = data->textures->line_start;
	line_end = data->textures->line_end;
	while (current_y < line_end)
	{
		color = get_texture_color(current_y, line_start, line_end, tex_x, tex);
		put_one_pixel(data, x, current_y, color);
		current_y++;
	}
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
