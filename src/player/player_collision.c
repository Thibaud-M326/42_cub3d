/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 16:05:06 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"

int	hitbox_check(t_data *data, int points[4][2])
{
	t_map	*map;
	double	pos_x;
	double	pos_y;
	int		i;

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

int	hitbox(t_data *data, double x, double y)
{
	int	points[4][2];
	int	hitbox;

	points[0][0] = x - HITBOX_RADIUS;
	points[0][1] = y - HITBOX_RADIUS;
	points[1][0] = x + HITBOX_RADIUS;
	points[1][1] = y - HITBOX_RADIUS;
	points[2][0] = x - HITBOX_RADIUS;
	points[2][1] = y + HITBOX_RADIUS;
	points[3][0] = x + HITBOX_RADIUS;
	points[3][1] = y + HITBOX_RADIUS;
	hitbox = hitbox_check(data, points);
	return (hitbox);
}
