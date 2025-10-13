/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:15:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/13 14:20:08 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	raycasting(t_data *data)
{
	int		x;
	double	camera_x;
	double	plane_x;	
	double	plane_y;

	plane_x = -data->player->dir_y * 0.66;
	plane_y = data->player->dir_x * 0.66;
	x = 0;
	while (x < 1000)
	{
		camera_x = 2 * x / (double)1000 - 1;
		data->player->ray.dir_x = data->player->dir_x + plane_x * camera_x;
		data->player->ray.dir_y = data->player->dir_y + plane_y * camera_x;

        raycasting_init(data);
        raycasting_dda(data);
        
		draw_vertical_line(data, x);
		x++;
	}
	return (1);
}