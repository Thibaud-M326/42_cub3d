/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:01:48 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/25 18:19:55 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"

t_player	*init_player_struct(t_data *data)
{
	t_player	*player;

	player = ft_calloc(1, sizeof(t_player));
	if (!player)
		free_and_exit(data, MALLOC, 1);
	return (player);
}
