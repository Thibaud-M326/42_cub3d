/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:53:03 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 20:02:21 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include "mlx.h"
#include <stdlib.h>

int	init_texture_img(t_data *data, t_mlx_img **tex)
{
	*tex = malloc(sizeof(t_mlx_img));
	if (!*tex)
		free_and_exit(data, TEX_MALLOC_FAILED, 1);
	return (1);
}

int	load_texture_img(t_data *data, t_mlx_img *tex, char card)
{
	char	*tex_path;

	if (card == 'n')
		tex_path = data->textures->path_n;
	if (card == 'e')
		tex_path = data->textures->path_e;
	if (card == 'w')
		tex_path = data->textures->path_w;
	if (card == 's')
		tex_path = data->textures->path_s;
	tex->img_ptr = mlx_xpm_file_to_image(
			data->mlx_data->mlx_ptr,
			tex_path,
			&tex->width,
			&tex->height);
	tex->img_data = mlx_get_data_addr(
			tex->img_ptr,
			&tex->bpp,
			&tex->size_line,
			&tex->endian);
	return (1);
}

int	load_textures(t_data *data)
{
	init_texture_img(data, &data->textures->tex_n);
	init_texture_img(data, &data->textures->tex_e);
	init_texture_img(data, &data->textures->tex_w);
	init_texture_img(data, &data->textures->tex_s);
	load_texture_img(data, data->textures->tex_n, 'n');
	load_texture_img(data, data->textures->tex_e, 'e');
	load_texture_img(data, data->textures->tex_w, 'w');
	load_texture_img(data, data->textures->tex_s, 's');
	return (1);
}
