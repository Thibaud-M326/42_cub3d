/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:53:03 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:18:18 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include "free_exit.h"
#include "mlx.h"
#include <stdlib.h>

int	init_texture_img(t_data *data, t_mlx_img **tex)
{
	*tex = malloc(sizeof(t_mlx_img));
	if (!*tex)
		free_and_exit(data, TEX_MALLOC_FAILED, 1);
	return (1);
}

int	load_texture_img(t_data *data, t_mlx_img *tex, char tex_side)
{
	char	*tex_path;

	if (tex_side == 'n')
		tex_path = data->textures->path_n;
	if (tex_side == 'e')
		tex_path = data->textures->path_e;
	if (tex_side == 'w')
		tex_path = data->textures->path_w;
	if (tex_side == 's')
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
