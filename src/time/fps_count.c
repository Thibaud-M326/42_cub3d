/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 18:09:46 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/27 18:35:15 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	fps_count(t_data *data)
{
	data->fps->old_time = data->fps->time;
	data->fps->time = get_current_time_ms();
	data->fps->fps_count = (data->fps->time - data->fps->old_time) / 1000.0;
	data->fps->move_speed = data->fps->fps_count * 3.0;
	data->fps->rot_speed = data->fps->fps_count * 2.0;
	return (1);
}
