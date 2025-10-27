/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:06:40 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:08:43 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "structures.h"

int	player_move_forward(t_data *data)
{
	t_player	*player;
	double		move_speed;
	double		next_x;
	double		next_y;

	player = data->player;
	move_speed = data->fps->move_speed;
	next_x = player->pos_x + player->dir_x * move_speed;
	next_y = player->pos_y + player->dir_y * move_speed;
	if (hitbox(data, next_x, player->pos_y))
		player->pos_x = next_x;
	if (hitbox(data, player->pos_x, next_y))
		player->pos_y = next_y;
	return (1);
}

int	player_move_backward(t_data *data)
{
	t_player	*player;
	double		move_speed;
	double		next_x;
	double		next_y;

	player = data->player;
	move_speed = data->fps->move_speed;
	next_x = player->pos_x - player->dir_x * move_speed;
	next_y = player->pos_y - player->dir_y * move_speed;
	if (hitbox(data, next_x, player->pos_y))
		player->pos_x = next_x;
	if (hitbox(data, player->pos_x, next_y))
		player->pos_y = next_y;
	return (1);
}

int	player_move_left(t_data *data)
{
	double		rot_dir_x;
	double		rot_dir_y;
	double		next_x;
	double		next_y;
	t_player	*player;

	player = data->player;
	rot_dir_x = -player->dir_y;
	rot_dir_y = player->dir_x;
	next_x = player->pos_x - rot_dir_x * data->fps->move_speed;
	next_y = player->pos_y - rot_dir_y * data->fps->move_speed;
	if (hitbox(data, next_x, player->pos_y))
		player->pos_x = next_x;
	if (hitbox(data, player->pos_x, next_y))
		player->pos_y = next_y;
	return (1);
}

int	player_move_right(t_data *data)
{
	double		rot_dir_x;
	double		rot_dir_y;
	double		next_x;
	double		next_y;
	t_player	*player;

	player = data->player;
	rot_dir_x = -player->dir_y;
	rot_dir_y = player->dir_x;
	next_x = player->pos_x + rot_dir_x * data->fps->move_speed;
	next_y = player->pos_y + rot_dir_y * data->fps->move_speed;
	if (hitbox(data, next_x, player->pos_y))
		player->pos_x = next_x;
	if (hitbox(data, player->pos_x, next_y))
		player->pos_y = next_y;
	return (1);
}

int	player_move(t_data *data)
{
	if (data->key->w)
		player_move_forward(data);
	else if (data->key->s)
		player_move_backward(data);
	if (data->key->a)
		player_move_left(data);
	if (data->key->d)
		player_move_right(data);
	if (data->key->left)
		player_turn_left(data);
	else if (data->key->right)
		player_turn_right(data);
	return (1);
}
