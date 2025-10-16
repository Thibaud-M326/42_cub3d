/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_vertical_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/16 18:24:31 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <stdio.h>
#include <math.h>

	// if (ray->side == 0)
	// 	tex_x = get_texture_x(ray->hit_pos_y, tex);
	// else
	// 	tex_x = get_texture_x(ray->hit_pos_x, tex);

int	get_tex_color(t_mlx_img *tex, int x, int y)
{
	int	byte;
	int	pixel_index;
	int	tex_pixel_color;

	byte = 8;
	pixel_index = (tex->size_line * y) + ((tex->bits_per_pixel / byte) * x);
	tex_pixel_color = *(int *)&(tex->img_data[pixel_index]);
	return (tex_pixel_color);
}

int	get_texture_color(int y, int line_start, int line_end, int tex_x, t_mlx_img *tex)
{
	int     tex_y;
	double  step;
	double  tex_pos;
	int     line_height;

	line_height = line_end - line_start;
	step = (double)tex->height / line_height;
	tex_pos = (y - line_start) * step;
	tex_y = (int)tex_pos;
	return (get_tex_color(tex, tex_x, tex_y));
}

int	draw_vert_texture(t_data *data, int x, int line_start, int line_end, int tex_x, t_mlx_img *tex)
{
	int	color;
	int	current_y;

	current_y = line_start;
	while (current_y < line_end)
	{
		color = get_texture_color(current_y, line_start, line_end, tex_x, tex);
		put_one_pixel(data, x, current_y, color);
		current_y++;
	}
	return (1);
}

int	ray_hit_point(t_data *data)
{
	t_player	*p;

	p = data->player;
	p->ray.hit_pos_x = p->pos_x + (p->ray.dir_x * p->ray.distance);
	p->ray.hit_pos_y = p->pos_y + (p->ray.dir_y * p->ray.distance);
	return (1);
}

double	get_texture_x(double hit_pos, t_mlx_img *tex)
{
	double		tex_x;
	double		floor_pos;

	floor_pos = floor(hit_pos);
	tex_x = hit_pos - floor_pos;
	tex_x = tex_x * tex->width;
	return (tex_x);
}

double	get_texture_x_revert(double hit_pos, t_mlx_img *tex)
{
	double		tex_x;
	double		floor_pos;

	floor_pos = ceil(hit_pos);
	tex_x = floor_pos - hit_pos;
	tex_x = tex_x * tex->width;
	return (tex_x);
}

int	get_texture_side(t_data *data, t_mlx_img **tex)
{
	t_ray	*ray;
	int		tex_x;

	ray = &data->player->ray;
	if (ray->side == 0)
	{
		if (ray->dir_x >= 0)
		{
			*tex = data->textures->tex_w;
			tex_x = get_texture_x(ray->hit_pos_y, *tex);
		}
		else
		{
			*tex = data->textures->tex_e;
			tex_x = get_texture_x_revert(ray->hit_pos_y, *tex);
		}
	}
	else
	{
		if (ray->dir_y >= 0)
		{
			*tex = data->textures->tex_n;
			tex_x = get_texture_x_revert(ray->hit_pos_x, *tex);
		}
		else
		{
			*tex = data->textures->tex_s;
			tex_x = get_texture_x(ray->hit_pos_x, *tex);
		}
	}
	return (tex_x);
}

int	draw_vertical_line(t_data *data, int x)
{
	t_ray		*ray;
	t_mlx_img	*tex;
	int			line_h;
	int			line_start;
	int			line_end;
	int			color;
	double		tex_x;

	tex = NULL;
	ray = &data->player->ray;
	color = 0x3ED6D2;
	ray_hit_point(data);
	tex_x = get_texture_side(data, &tex);

	// if (ray->side == 0)
	// 	tex_x = get_texture_x(ray->hit_pos_y, tex);
	// else
	// 	tex_x = get_texture_x(ray->hit_pos_x, tex);

	line_h = 1000 / ray->distance;
	line_start = -line_h / 2 + 1000 / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_h / 2 + 1000 / 2;
	if (line_end >= 1000)
		line_end = 1000 - 1;
	if (ray->side == 1)
		color /= 2;
	draw_vert_texture(data, x, line_start, line_end, tex_x, tex);
	return (1);
}
