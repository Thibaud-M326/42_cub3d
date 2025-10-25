/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 21:30:52 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"

static double	**init_points(double x, double y)
{
	double	points[4][2];

	points[0][0] = x - HITBOX_RADIUS;
	points[0][1] = y - HITBOX_RADIUS;
	points[1][0] = x + HITBOX_RADIUS;
	points[1][1] = y - HITBOX_RADIUS;
	points[2][0] = x - HITBOX_RADIUS;
	points[2][1] = y + HITBOX_RADIUS;
	points[3][0] = x + HITBOX_RADIUS;
	points[3][1] = y + HITBOX_RADIUS;
	return (points);
}

int	hitbox_clear(t_data *data, double x, double y)
{
	double	pos_x;
	double	pos_y;
	int		i;
	t_map	*map;
	double	**points;

	map = data->map;
	points = init_points(x, y);
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
