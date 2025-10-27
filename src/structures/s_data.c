/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:11 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "libft.h"

t_data	*init_data_struct(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		free_and_exit(data, "Malloc failed", 1);
	data->file = NULL;
	data->textures = NULL;
	data->map = NULL;
	data->minimap = NULL;
	data->check = NULL;
	data->mlx_data = NULL;
	data->player = NULL;
	data->key = NULL;
	data->fps = NULL;
	return (data);
}
