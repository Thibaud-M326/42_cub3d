/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/22 19:21:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "minimap.h"
#include <math.h>

int	hitbox_clear(t_data *data, double x, double y)
{
	double	angle;
	double	px;
	double	py;
	int		i;
	t_map	*map;

	map = data->map;
	i = 0;
	while (i < 8)
	{
		angle = (3.14 / 4.0) * i;
		px = x + HITBOX_RADIUS * cos(angle);
		py = y + HITBOX_RADIUS * sin(angle);
		if (!(py > 0 && py < map->height) || !(px > 0
				&& px < get_map_line_len(map->map[(int)py])))
			free_and_exit(data, OUT_BOUNDS, 1);
		if (map->map[(int)py][(int)px] == '1')
			return (0);
		i++;
	}
	return (1);
}
