/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:18:11 by jmagand           #+#    #+#             */
/*   Updated: 2025/10/06 18:37:51 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include <stddef.h>

t_data	*init_data_struct(void)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		free_and_exit(data, "Malloc failed", 1);
	data->file = NULL;
	data->textures = NULL;
	data->map = NULL;
	data->check = NULL;
	data->mlx_data = NULL;
	data->player = NULL;
	return (data);
}
