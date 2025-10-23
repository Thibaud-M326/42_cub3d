/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:57:19 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/23 14:49:18 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_tex_color(t_mlx_img *tex, int x, int y)
{
	int	byte;
	int	pixel_index;
	int	tex_pixel_color;

	byte = 8;
	pixel_index = (tex->size_line * y) + ((tex->bpp / byte) * x);
	tex_pixel_color = *(int *)&(tex->img_data[pixel_index]);
	return (tex_pixel_color);
}

double	get_texture_color(t_data *data, t_mlx_img *tex, int y, int tex_x)
{
	int		tex_y;
	double	step;
	double	tex_pos;
	int		line_height;

	line_height = data->textures->line_end - data->textures->line_start;
	step = (double)tex->height / line_height;
	tex_pos = (y - data->textures->line_start) * step;
	tex_y = (int)tex_pos;
	return (get_tex_color(tex, tex_x, tex_y));
}
