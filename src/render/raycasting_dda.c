/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_dda.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:26:27 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/21 20:50:10 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	first_side_ray_dist(t_data *data)
{
	t_ray		*ray;
	t_player	*player;

	ray = &data->player->ray;
	player = data->player;
	if (ray->dir_x < 0)
		ray->length_x = player->offset_pos_x * ray->unit_length_x;
	else
		ray->length_x = (1 - player->offset_pos_x) * ray->unit_length_x;
	if (ray->dir_y < 0)
		ray->length_y = player->offset_pos_y * ray->unit_length_y;
	else
		ray->length_y = (1 - player->offset_pos_y) * ray->unit_length_y;
	return (1);
}

int	compute_ray_distance(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->length_x < ray->length_y)
	{
		data->player->ray.distance = ray->length_x;
		data->player->ray.side = 0;
	}
	else
	{
		data->player->ray.distance = ray->length_y;
		data->player->ray.side = 1;
	}
	return (1);
}

int	hit_wall_ray_dist(t_data *data)
{
	t_ray	*ray;
	char	**map;

	ray = &data->player->ray;
	map = data->map->map;
	while (1)
	{
		if (ray->length_x < ray->length_y)
			ray->map_check_x += ray->step_x;
		else
			ray->map_check_y += ray->step_y;
		// if (((int)ray->map_check_y >= 0 && (int)ray->map_check_y < data->map->height) 
		// 	&& ((int)ray->map_check_x >= 0 && (int)ray->map_check_x < data->map->width))
		// {
		// }
		if (map[(int)ray->map_check_y][(int)ray->map_check_x] == '1')
			break ;
		if (ray->length_x < ray->length_y)
			ray->length_x += ray->unit_length_x;
		else
			ray->length_y += ray->unit_length_y;
	}
	compute_ray_distance(data);
	return (1);
}

int	raycasting_dda(t_data *data)
{
	first_side_ray_dist(data);
	hit_wall_ray_dist(data);
	return (1);
}
