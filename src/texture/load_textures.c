/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:53:03 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/14 14:48:18 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"

	#include <stdio.h>

int	load_texture_img(t_data *data, t_mlx_img *tex, char card)
{
	char	*tex_path;

	if (card == 'n')
		tex_path = data->textures->path_n;
	if (card == 'e')
		tex_path = data->textures->path_e;
	if (card == 'w')
		tex_path = data->textures->path_w;
	if (card == 't')
		tex_path = data->textures->path_s;
	printf("tex_path : %s\n", tex_path);
	tex->img_ptr = mlx_xpm_file_to_image(
			data->mlx_data->mlx_ptr,
			tex_path,
			&tex->width,
			&tex->height);
	tex->img_data = mlx_get_data_addr(
			tex->img_ptr,
			&tex->bits_per_pixel,
			&tex->size_line,
			&tex->endian);
	return (1);
}

int	load_textures(t_data *data)
{
	load_texture_img(data, &data->textures->tex_n, 'n');
	load_texture_img(data, &data->textures->tex_e, 'e');
	load_texture_img(data, &data->textures->tex_w, 'w');
	load_texture_img(data, &data->textures->tex_s, 's');
	return (1);
}
