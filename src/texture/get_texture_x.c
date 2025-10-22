/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:59:26 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/22 21:58:15 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include <math.h>

double	get_texture_x(double hit_pos, t_mlx_img *tex)
{
	double	tex_x;
	double	floor_pos;

	floor_pos = floor(hit_pos);
	tex_x = hit_pos - floor_pos;
	tex_x = tex_x * tex->width;
	return (tex_x);
}

double	get_texture_x_revert(double hit_pos, t_mlx_img *tex)
{
	double	tex_x;
	double	floor_pos;

	floor_pos = ceil(hit_pos);
	tex_x = floor_pos - hit_pos;
	tex_x = tex_x * tex->width;
	return (tex_x);
}

int	get_tex_x_side_x(t_data *data, t_mlx_img **tex)
{
	double	tex_x;
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->dir_x >= 0)
	{
		*tex = data->textures->tex_e;
		tex_x = get_texture_x(ray->hit_pos_y, *tex);
	}
	else
	{
		*tex = data->textures->tex_w;
		tex_x = get_texture_x_revert(ray->hit_pos_y, *tex);
	}
	return (tex_x);
}

int	get_tex_x_side_y(t_data *data, t_mlx_img **tex)
{
	double	tex_x;
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->dir_y >= 0)
	{
		*tex = data->textures->tex_s;
		tex_x = get_texture_x_revert(ray->hit_pos_x, *tex);
	}
	else
	{
		*tex = data->textures->tex_n;
		tex_x = get_texture_x(ray->hit_pos_x, *tex);
	}
	return (tex_x);
}

double	get_tex_x(t_data *data, t_mlx_img **tex)
{
	t_ray	*ray;
	int		tex_x;

	ray = &data->player->ray;
	if (ray->side == 0)
		tex_x = get_tex_x_side_x(data, tex);
	else
		tex_x = get_tex_x_side_y(data, tex);
	return (tex_x);
}
