/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_color.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 18:57:19 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/25 16:02:11 by thmaitre         ###   ########.fr       */
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

int	get_texture_color(t_data *data, t_mlx_img *tex, int win_y, int tex_x)
{
	int		tex_y;
	double	tex_step_y;
	double	tex_pos;
	int		wall_height;

	wall_height = data->textures->wall_end - data->textures->wall_start;
	tex_step_y = (double)tex->height / wall_height;
	tex_pos = tex_step_y * (win_y - data->textures->wall_start);
	tex_y = (int)tex_pos;
	return (get_tex_color(tex, tex_x, tex_y));
}
