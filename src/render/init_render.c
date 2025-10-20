/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:59:53 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/20 18:03:06 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

int	init_render(t_data *data)
{
	init_player_dir(data);
	load_textures(data);
	init_key_struct(data);
	init_fps_struct(data);
	data->minimap = init_minimap_struct(data);
	return (1);
}
