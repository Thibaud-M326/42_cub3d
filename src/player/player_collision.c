/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 20:51:24 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"

int	hitbox_clear(t_data *data, double x, double y)
{
	t_map	*map;
	int		i;
	double	px;
	double	py;

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
		px = points[i][0];
		py = points[i][1];
		if (!(py >= 0 && py < map->height) || !(px >= 0
				&& px < get_map_line_len(map->map[(int)py])))
			free_and_exit(data, OUT_BOUNDS, 1);
		if (map->map[(int)py][(int)px] == '1')
			return (0);
		i++;
	}
	return (1);
}

