/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:52:11 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/01 21:00:22 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int player_move_left(t_data *data)
{
    (void)data;
    data->player->pos_x -= 2;
    return (1);
}

int player_move_right(t_data *data)
{
    (void)data;
    data->player->pos_x += 2;
    return (1);
}

int player_move_up(t_data *data)
{
    (void)data;
    data->player->pos_y -= 2;
    return (1);
}

int player_move_down(t_data *data)
{
    (void)data;
    data->player->pos_y += 2;
    return (1);
}