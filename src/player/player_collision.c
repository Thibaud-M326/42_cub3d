/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 18:12:49 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"
#include <math.h>

int	hitbox_clear(t_data *data, double x, double y)
{
	double	angle;
	double	pos_x;
	double	pos_y;
	int		i;
	t_map	*map;

	map = data->map;
	i = 0;
	while (i < 8)
	{
		angle = (3.14 / 4.0) * i;
		pos_x = x + HITBOX_RADIUS * cos(angle);
		pos_y = y + HITBOX_RADIUS * sin(angle);
		if (!(pos_y > 0 && pos_y < map->height) || !(pos_x > 0
				&& pos_x < get_map_line_len(map->map[(int)pos_y])))
			free_and_exit(data, OUT_BOUNDS, 1);
		if (map->map[(int)pos_y][(int)pos_x] == '1')
			return (0);
		i++;
	}
	return (1);
}
