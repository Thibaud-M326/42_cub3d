/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:58:39 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	dir_north(t_data *data)
{
	data->player->dir_x = 0;
	data->player->dir_y = -1;
	return (1);
}

static int	dir_south(t_data *data)
{
	data->player->dir_x = 0;
	data->player->dir_y = 1;
	return (1);
}

static int	dir_east(t_data *data)
{
	data->player->dir_x = 1;
	data->player->dir_y = 0;
	return (1);
}

static int	dir_west(t_data *data)
{
	data->player->dir_x = -1;
	data->player->dir_y = 0;
	return (1);
}

int	init_player_dir(t_data *data)
{
	if (data->player->id == 'N')
		dir_north(data);
	if (data->player->id == 'S')
		dir_south(data);
	if (data->player->id == 'E')
		dir_east(data);
	if (data->player->id == 'W')
		dir_west(data);
	return (1);
}
