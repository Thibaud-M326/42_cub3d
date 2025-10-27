/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_fps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 17:39:07 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 19:15:00 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free_exit.h"
#include "structures.h"
#include <stdlib.h>

void	init_fps_struct(t_data *data)
{
	data->fps = malloc(sizeof(t_fps));
	if (!data->fps)
		free_and_exit(data, MALLOC, 1);
	data->fps->old_time = 0;
	data->fps->time = 0;
	data->fps->fps_count = 0;
	return ;
}

void	free_fps(t_fps *fps)
{
	if (fps)
	{
		free(fps);
		fps = NULL;
	}
	return ;
}
