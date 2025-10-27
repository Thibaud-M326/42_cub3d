/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:53:42 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include <math.h>

int	ray_step(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (player->ray.dir_x >= 0)
		player->ray.step_x = 1;
	else
		player->ray.step_x = -1;
	if (player->ray.dir_y >= 0)
		player->ray.step_y = 1;
	else
		player->ray.step_y = -1;
	return (1);
}

int	player_map_pos(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->ray.map_check_x = floor(player->pos_x);
	player->ray.map_check_y = floor(player->pos_y);
	return (1);
}

int	ray_unit_length(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (fabs(ray->dir_x) < 1e-10)
		ray->unit_length_x = 1e30;
	else
		ray->unit_length_x = fabs(1.0 / ray->dir_x);
	if (fabs(ray->dir_y) < 1e-10)
		ray->unit_length_y = 1e30;
	else
		ray->unit_length_y = fabs(1.0 / ray->dir_y);
	return (1);
}

int	player_offset_pos(t_data *data)
{
	t_player	*player;	

	player = data->player;
	player->offset_pos_x = player->pos_x - player->ray.map_check_x;
	player->offset_pos_y = player->pos_y - player->ray.map_check_y;
	return (0);
}

int	raycasting_init(t_data *data)
{
	ray_step(data);
	player_map_pos(data);
	ray_unit_length(data);
	player_offset_pos(data);
	return (1);
}
