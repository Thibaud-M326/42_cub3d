/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:59:53 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/28 20:58:39 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"
#include "parsing.h"
#include "minimap.h"

int	init_render(t_data *data)
{
	init_player_dir(data);
	load_textures(data);
	init_key_struct(data);
	init_fps_struct(data);
	data->minimap = init_minimap_struct(data);
	clear_image(data->minimap->bg_img, 0x303030);
	return (1);
}
