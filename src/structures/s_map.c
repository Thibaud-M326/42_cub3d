/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 15:48:50 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/15 22:06:54 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"

t_map	*init_map_struct(t_data *data)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		free_and_exit(data, MALLOC, 1);
	map->map = NULL;
	map->height = 0;
	map->width = 0;
	return (map);
}
