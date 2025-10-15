/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/15 19:31:16 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_one_pixel_img(t_mlx_img *img, int x, int y, int color)
{
	char	*pxl;

	pxl = img->img_data + (y * img->size_line + x * (img->bits_per_pixel / 8));
	*(int *)pxl = color;
}

void	put_one_pixel(t_data *data, int x, int y, int color)
{
	char	*offset;

	offset = data->mlx_data->mlx_img->img_data + (y
			* data->mlx_data->mlx_img->size_line + x
			* data->mlx_data->mlx_img->bits_per_pixel / 8);
	*(unsigned int *)offset = color;
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
