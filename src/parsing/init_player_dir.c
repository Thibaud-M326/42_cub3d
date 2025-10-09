/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:58:39 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/09 20:05:14 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"

int dir_north(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = -1;
    return (1);
}

int dir_south(t_player *player)
{
    player->dir_x = 0;
    player->dir_y = 1;
    return (1);
}

int dir_east(t_player *player)
{
    player->dir_x = 1;
    player->dir_y = 0;
    return (1);
}

int dir_west(t_player *player)
{
    player->dir_x = -1;
    player->dir_y = 0;
    return (1);
}

int init_player_dir(t_data *data)
{
    t_player    *player;

    player = data->player;
    if (player->id == 'N')
        dir_north(player);
    if (player->id == 'S')
        dir_south(player);
    if (player->id == 'E')
        dir_east(player);
    if (player->id == 'W')
        dir_west(player);
    return (1);
}