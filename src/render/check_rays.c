/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:14:54 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:09:20 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_exit.h"
#include "minimap.h"
#include "structures.h"

int	check_ray_y(t_data *data, double next_y)
{
	t_map	*map;
	t_ray	*ray;

	map = data->map;
	ray = &data->player->ray;
	next_y += ray->step_y;
	if (!(next_y >= 0 && next_y < map->height))
		free_and_exit(data, RAY_Y_BOUNDS, 1);
	return (1);
}

int	check_ray_x(t_data *data, double next_x)
{
	t_map	*map;
	t_ray	*ray;

	map = data->map;
	ray = &data->player->ray;
	next_x += ray->step_x;
	if (!(next_x >= 0
			&& next_x < get_map_line_len(map->map[(int)data->player->pos_y])))
		free_and_exit(data, RAY_X_BOUNDS, 1);
	return (1);
}
