/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 14:15:01 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 18:27:06 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

	#include <stdio.h>

int	raycasting(t_data *data)
{
	int		x;
	double	camera_x;
	double	plane_x;	
	double	plane_y;
	int		win_w;

	win_w = data->mlx_data->mlx_img->width;
	plane_x = -data->player->dir_y * 0.66;
	plane_y = data->player->dir_x * 0.66;
	x = 0;
	printf("player->dir_x :%f plane_x :%f \n", data->player->dir_x, plane_x);
	printf("player->dir_y :%f plane_y :%f \n", data->player->dir_y, plane_y);
	while (x < win_w)
	{
		camera_x = 2 * (x / (double)win_w) - 1;
		data->player->ray.dir_x = data->player->dir_x + plane_x * camera_x;
		data->player->ray.dir_y = data->player->dir_y + plane_y * camera_x;
		raycasting_init(data);
		raycasting_dda(data);
		draw_textures(data, x);
		x++;
	}
	return (1);
}
