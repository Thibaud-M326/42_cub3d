/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:51:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/15 01:13:44 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	put_one_pixel(t_data *data, int x, int y, int color)
{
	char	*offset;

	offset = data->mlx_data->mlx_img->img_data + (y
			* data->mlx_data->mlx_img->size_line + x
			* data->mlx_data->mlx_img->bits_per_pixel / 8);
			// (data->mlx_data->mlx_img->size_line
		// * y) +
		// (x * (data->mlx_data->mlx_img->bits_per_pixel / 8));
	*(unsigned int *)offset = color;
}

int	mix_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16) | (green << 8) | blue;
	return (color);
}
