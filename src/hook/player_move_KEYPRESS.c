/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_KEYPRESS.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:06:40 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 18:54:34 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	player_moove_up(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->pos_x += player->dir_x * 0.1;
	player->pos_y += player->dir_y * 0.1;
	return (1);
}

int	player_moove_down(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->pos_x -= player->dir_x * 0.1;
	player->pos_y -= player->dir_y * 0.1;
	return (1);
}

int	player_moove_KEYPRESS(t_data *data)
{
	if (data->key->up)
		player_moove_up(data);
	else if (data->key->down)
		player_moove_down(data);
	return (1);
}
