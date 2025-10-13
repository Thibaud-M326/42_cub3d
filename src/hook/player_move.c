/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:52:11 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/13 14:36:32 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "math.h"

int	player_move_forward(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->pos_x += player->dir_x * 0.5;
	player->pos_y += player->dir_y * 0.5;
	return (1);
}

int	player_move_backward(t_data *data)
{
	t_player	*player;

	player = data->player;
	player->pos_x -= player->dir_x * 0.5;
	player->pos_y -= player->dir_y * 0.5;
	return (1);
}

int	player_turn_left(t_data *data)
{
	double	old_d_x;
	double	old_dir_y;
	double	rot_speed;

	rot_speed = -0.2;
	old_d_x = data->player->dir_x;
	old_dir_y = data->player->dir_y;
	data->player->dir_x = old_d_x * cos(rot_speed) - old_dir_y * sin(rot_speed);
	data->player->dir_y = old_d_x * sin(rot_speed) + old_dir_y * cos(rot_speed);
	return (1);
}

int	player_turn_right(t_data *data)
{
	double	old_d_x;
	double	old_dir_y;
	double	rot_speed;

	rot_speed = 0.2;
	old_d_x = data->player->dir_x;
	old_dir_y = data->player->dir_y;
	data->player->dir_x = old_d_x * cos(rot_speed) - old_dir_y * sin(rot_speed);
	data->player->dir_y = old_d_x * sin(rot_speed) + old_dir_y * cos(rot_speed);
	return (1);
}
