/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2025/10/01 19:55:22 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/09 19:02:15 by jmagand          ###   ########.fr       */
=======
/*   Created: 2025/10/08 18:01:48 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/09 19:59:49 by jmagand          ###   ########.fr       */
>>>>>>> origin/parsing110
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

