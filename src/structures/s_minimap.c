/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:38:27 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/15 19:18:59 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "messages.h"
#include "minimap.h"

t_minimap	*init_minimap_struct(t_data *data)
{
	t_minimap	*mini;

	mini = ft_calloc(1, sizeof(t_minimap));
	if (!mini)
		free_and_exit(data, MALLOC, 1);
	mini->x = 0;
	mini->y = 0;
	mini->height = data->map->height;
	mini->width = data->map->width;
	mini->img = malloc(sizeof(t_mlx_img));
	if (!mini->img)
		free_and_exit(data, MALLOC, 1);
	data->minimap = mini;
	return (mini);
}
