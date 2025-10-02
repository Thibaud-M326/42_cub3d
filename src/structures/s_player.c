/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:55:22 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/02 15:50:57 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

int init_player_struct(t_data *data)
{
    data->player = ft_calloc(1, sizeof(t_player));
    if (!data->player)
        free_and_exit(data, msg_predefined(MALLOC), 1);
    data->player->pos_x = 250;
    data->player->pos_y = 750;
    data->player->dir_x = 0.5;
    data->player->dir_y = 0.5;
    return (1);
}
