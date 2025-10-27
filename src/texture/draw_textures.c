/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 19:12:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:19:59 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

int	get_wall_start_end(t_data *data)
{
	int			wall_h;
	int			win_h;

	win_h = data->mlx_data->mlx_img->height;
	wall_h = win_h / data->player->ray.distance;
	data->textures->wall_start = -wall_h / 2 + win_h / 2;
	data->textures->wall_end = wall_h / 2 + win_h / 2;
	return (1);
}

int	draw_textures(t_data *data, int win_x)
{
	t_mlx_img	*tex;
	double		tex_x;

	ray_hit_point(data);
	tex = get_tex(data);
	tex_x = get_tex_x(data, &tex);
	get_wall_start_end(data);
	draw_texture(data, tex, tex_x, win_x);
	return (1);
}
