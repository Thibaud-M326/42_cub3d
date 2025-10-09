/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/01 21:11:45 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_one_pixel(t_data *data, int x, int y, int color)
{
	int	offset;

	offset = (data->mlx_data->mlx_img->size_line * y) + (x * (data->mlx_data->mlx_img->bits_per_pixel / 8));
	*((unsigned int *)(offset + data->mlx_data->mlx_img->img_data)) = color;
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
