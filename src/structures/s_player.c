/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:01:48 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/08 18:11:53 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"

t_player	*init_player_struct(t_data *data)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		free_and_exit(data, MALLOC, 1);
	player->pos_x = -1;
	player->pos_y = -1;
	player->id = '\0';
	return (player);
}
