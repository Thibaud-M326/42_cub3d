/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/29 15:58:51 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

void	put_one_pixel_img(t_mlx_img *img, int x, int y, int color)
{
	char	*pxl;

	if ((y >= 0 && y < HEIGHT) && (x >= 0 && x < WIDTH))
	{
		pxl = img->img_data + (y * img->size_line + x * (img->bpp / 8));
		*(unsigned int *)pxl = color;
	}
}

int	are_pixels_in_window(int win_x, int win_y)
{
	if (((win_y >= 0 && win_y < HEIGHT) && (win_x >= 0 && win_x < WIDTH))
		&& ((win_y >= 0 && win_y < HEIGHT)
			&& (win_x + 1 >= 0 && win_x + 1 < WIDTH)))
		return (1);
	return (0);
}

void	put_two_pixel(t_data *data, int win_x, int win_y, int color)
{
	int		offset_one;
	int		offset_two;
	char	*img_data;
	int		size_line;
	int		bpp;

	img_data = data->mlx_data->mlx_img->img_data;
	size_line = data->mlx_data->mlx_img->size_line;
	bpp = data->mlx_data->mlx_img->bpp;
	if (are_pixels_in_window(win_x, win_y))
	{
		offset_one = (size_line * win_y) + (win_x * (bpp / 8));
		*((unsigned int *)(offset_one + img_data)) = color;
		offset_two = (size_line * win_y) + ((win_x + 1) * (bpp / 8));
		*((unsigned int *)(offset_two + img_data)) = color;
	}
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
