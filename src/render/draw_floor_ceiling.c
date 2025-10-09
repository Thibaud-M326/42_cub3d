/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:56:06 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/09 21:48:06 by jmagand          ###   ########.fr       */
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
	while (y < 1000 * 0.5 + 1000 * 0.5)
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
	while (y < 1000 * 0.5)
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