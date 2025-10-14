/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:56:06 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/14 19:55:31 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	draw_floor(t_data *data)
{
	int	y;
	int	x;
	int	floor_color;

	y = 0;
	x = 0;
	floor_color = data->textures->floor_color;
	while (y < 1000 / 2 + 1000 / 2)
	{
		x = 0;
		while (x < 1000)
		{
			put_one_pixel(data, x, y, floor_color);
			x++;
		}
		y++;
	}
	return (1);
}

int	draw_ceiling(t_data *data)
{
	int	y;
	int	x;
	int	ceil_color;

	y = 0;
	x = 0;
	ceil_color = data->textures->ceil_color;
	while (y < 1000 / 2)
	{
		x = 0;
		while (x < 1000)
		{
			put_one_pixel(data, x, y, ceil_color);
			x++;
		}
		y++;
	}
	return (1);
}

int	draw_floor_ceiling(t_data *data)
{
	draw_floor(data);
	draw_ceiling(data);
	return (1);
}
