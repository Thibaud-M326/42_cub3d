/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:06:40 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/22 16:23:16 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "messages.h"
#include <math.h>

	#include <stdio.h>

int	player_moove_forward(t_data *data)
{
	t_player	*player;

	player = data->player;

	printf("collision : %d\n", collision(data->map->map, player->pos_x, player->pos_y));
	player->pos_x += player->dir_x * data->fps->move_speed;
	player->pos_y += player->dir_y * data->fps->move_speed;
	return (1);
}

int	player_moove_backward(t_data *data)
{
	t_player	*player;

	player = data->player;
	printf("collision : %d\n", collision(data->map->map, player->pos_x, player->pos_y));
	player->pos_x -= player->dir_x * data->fps->move_speed;
	player->pos_y -= player->dir_y * data->fps->move_speed;
	return (1);
}

int	player_moove_left(t_data *data)
{
	double		rad_angle;
	double		rot_dir_x;
	double		rot_dir_y;
	double		old_dir_x;
	double		old_dir_y;

	rad_angle = 1.5708;
	old_dir_x = data->player->dir_x;
	old_dir_y = data->player->dir_y;
	rot_dir_x = old_dir_x * cos(rad_angle) - old_dir_y * sin(rad_angle);
	rot_dir_y = old_dir_x * sin(rad_angle) + old_dir_y * cos(rad_angle);
	printf("collision : %d\n", collision(data->map->map, data->player->pos_x, data->player->pos_y));
	data->player->pos_x -= rot_dir_x * data->fps->move_speed;
	data->player->pos_y -= rot_dir_y * data->fps->move_speed;
	return (1);
}

int	player_moove_right(t_data *data)
{
	double		rad_angle;
	double		rot_dir_x;
	double		rot_dir_y;
	double		old_dir_x;
	double		old_dir_y;

	rad_angle = 1.5708;
	old_dir_x = data->player->dir_x;
	old_dir_y = data->player->dir_y;
	rot_dir_x = old_dir_x * cos(rad_angle) - old_dir_y * sin(rad_angle);
	rot_dir_y = old_dir_x * sin(rad_angle) + old_dir_y * cos(rad_angle);
	printf("collision : %d\n", collision(data->map->map, data->player->pos_x, data->player->pos_y));
	data->player->pos_x += rot_dir_x * data->fps->move_speed;
	data->player->pos_y += rot_dir_y * data->fps->move_speed;
	return (1);
}

int	player_moove(t_data *data)
{
	if (data->key->w)
		player_moove_forward(data);
	else if (data->key->s)
		player_moove_backward(data);
	if (data->key->a)
		player_moove_left(data);
	if (data->key->d)
		player_moove_right(data);
	if (data->key->left)
		player_turn_left(data);
	else if (data->key->right)
		player_turn_right(data);
	return (1);
}
