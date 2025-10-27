/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:14:05 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	get_tex_side_x(t_data *data, t_mlx_img **tex)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->dir_x >= 0)
		*tex = data->textures->tex_w;
	else
		*tex = data->textures->tex_e;
	return (1);
}

int	get_tex_side_y(t_data *data, t_mlx_img **tex)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->dir_y >= 0)
		*tex = data->textures->tex_n;
	else
		*tex = data->textures->tex_s;
	return (1);
}

t_mlx_img	*get_tex(t_data *data)
{
	t_ray		*ray;
	t_mlx_img	*tex;

	ray = &data->player->ray;
	if (ray->side == 0)
		get_tex_side_x(data, &tex);
	else
		get_tex_side_y(data, &tex);
	return (tex);
}
