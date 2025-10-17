/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 17:13:43 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_one_pixel(t_data *data, int x, int y, int color)
{
	int	offset;
	int	win_w;
	int	win_h;

	win_w = data->mlx_data->mlx_img->width;
	win_h = data->mlx_data->mlx_img->height;
	if ((y >= 0 && y < win_h) && (x >= 0 && x < win_w))
	{
		offset = (data->mlx_data->mlx_img->size_line * y)
			+ (x * (data->mlx_data->mlx_img->bits_per_pixel / 8));
		*((unsigned int *)(offset + data->mlx_data->mlx_img->img_data)) = color;
	}
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
