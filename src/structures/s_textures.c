/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:59:16 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/23 23:22:08 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "mlx.h"

t_textures	*init_textures_struct(t_data *data)
{
	t_textures	*textures;

	textures = ft_calloc(1, sizeof(t_textures));
	if (!textures)
		free_and_exit(data, MALLOC, 1);
	else
	{
		textures->floor_color = 0;
		textures->ceil_color = 0;
		textures->path_n = NULL;
		textures->path_s = NULL;
		textures->path_e = NULL;
		textures->path_w = NULL;
		textures->extension = NULL;
		textures->tex_n = NULL;
		textures->tex_e = NULL;
		textures->tex_w = NULL;
		textures->tex_s = NULL;
		textures->face = 0;
		textures->line_start = 0;
		textures->line_end = 0;
	}
	return (textures);
}

void	free_texture_img(t_data *data, t_mlx_img *tex)
{
	if (tex->img_ptr)
		mlx_destroy_image(data->mlx_data->mlx_ptr, tex->img_ptr);
	free(tex);
	tex = NULL;
	return ;
}

void	free_textures(t_data *data, t_textures *textures)
{
	if (textures)
	{
		if (textures->path_n)
			free(textures->path_n);
		if (textures->path_s)
			free(textures->path_s);
		if (textures->path_e)
			free(textures->path_e);
		if (textures->path_w)
			free(textures->path_w);
		if (textures->tex_n)
			free_texture_img(data, textures->tex_n);
		if (textures->tex_e)
			free_texture_img(data, textures->tex_e);
		if (textures->tex_w)
			free_texture_img(data, textures->tex_w);
		if (textures->tex_s)
			free_texture_img(data, textures->tex_s);
		free(textures);
	}
}
