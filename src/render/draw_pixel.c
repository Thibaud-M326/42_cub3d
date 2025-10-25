/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 20:59:57 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_one_pixel_img(t_mlx_img *img, int x, int y, int color)
{
	char	*pxl;

	if ((y >= 0 && y < HEIGHT) && (x >= 0 && x < WIDTH))
	{
		pxl = img->img_data + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

void	put_one_pixel(t_data *data, int win_x, int win_y, int color)
{
	int	offset;

	if ((win_y >= 0 && win_y < HEIGHT) && (win_x >= 0 && win_x < WIDTH))
	{
		offset = (data->mlx_data->mlx_img->size_line * win_y)
			+ (win_x * (data->mlx_data->mlx_img->bpp / 8));
		*((unsigned int *)(offset + data->mlx_data->mlx_img->img_data)) = color;
	}
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
