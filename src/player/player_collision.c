/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 20:09:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/22 16:41:36 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

	#include <stdio.h>

//si collsion return 1 sinon 0
int	collision(char **map, int x, int y)
{
	int	i;
	int col_dir_y;
	int col_dir_x;
	double	radius;
	int	collision_dir[8][2] = {
	{y - 1, x - 1},
	{y - 1, x},
	{y - 1, x + 1},
	{y, x - 1},
	{y, x + 1},
	{y + 1, x - 1},
	{y + 1, x},
	{y + 1, x + 1}
	};

	printf("x %d\n", x);
	printf("y %d\n", y);
	i = 0;
	radius = 0.25;
	while (i < 8)
	{
		col_dir_y = (int)(y + collision_dir[i][0] * radius);
		col_dir_x = (int)(x + collision_dir[i][1] * radius);

		printf("collision_dir_y %d\n", collision_dir[i][0]);
		printf("collision_dir_x %d\n\n", collision_dir[i][1]);

		// printf("col_dir_x %d\n", col_dir_x);
		// printf("col_dir_y %d\n", col_dir_y);
		if (map[col_dir_y][col_dir_x] == '1')
			return (1);
		i++;
	}
	return (0);
}
