/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 15:16:34 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:08:55 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structures.h"
#include <math.h>

int	player_turn_left(t_data *data)
{
	double	old_d_x;
	double	old_dir_y;
	double	rot_speed;

	rot_speed = -data->fps->rot_speed;
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

	rot_speed = data->fps->rot_speed;
	old_d_x = data->player->dir_x;
	old_dir_y = data->player->dir_y;
	data->player->dir_x = old_d_x * cos(rot_speed) - old_dir_y * sin(rot_speed);
	data->player->dir_y = old_d_x * sin(rot_speed) + old_dir_y * cos(rot_speed);
	return (1);
}
