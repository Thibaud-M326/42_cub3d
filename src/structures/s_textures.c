/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_textures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:59:16 by jmagand           #+#    #+#             */
/*   Updated: 2025/09/30 22:49:41 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

t_textures	*init_textures_struct(t_data *data)
{
	t_textures	*textures;

	textures = ft_calloc(1, sizeof(t_textures));
	if (!textures)
		free_and_exit(data, msg_predefined(MALLOC), 1);
	else
	{
		textures->floor_color = 0;
		textures->ceil_color = 0;
		textures->path_n = NULL;
		textures->path_s = NULL;
		textures->path_e = NULL;
		textures->path_w = NULL;
	}
	return (textures);
}

void	free_textures(t_textures *textures)
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
		free(textures);
	}
}
