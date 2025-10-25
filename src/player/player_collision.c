/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 18:20:17 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"

int	hitbox_clear(t_data *data, double x, double y)
{
	double	pos_x;
	double	pos_y;
	int		i;
	t_map	*map;

	double points[4][2] = {
		{x - HITBOX_RADIUS, y - HITBOX_RADIUS},
		{x + HITBOX_RADIUS, y - HITBOX_RADIUS},
		{x - HITBOX_RADIUS, y + HITBOX_RADIUS},
		{x + HITBOX_RADIUS, y + HITBOX_RADIUS}
	};
	map = data->map;
	i = 0;
	while (i < 4)
	{
		pos_x = points[i][0];
		pos_y = points[i][1];
		if (!(pos_y >= 0 && pos_y < map->height) || !(pos_x >= 0
				&& pos_x < get_map_line_len(map->map[(int)pos_y])))
			free_and_exit(data, OUT_BOUNDS, 1);
		if (map->map[(int)pos_y][(int)pos_x] == '1')
			return (0);
		i++;
	}
	return (1);
}

