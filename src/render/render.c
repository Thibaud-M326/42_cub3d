/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/13 14:18:59 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "parsing.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <X11/keysym.h>

int	render(t_data *data)
{
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr, data->mlx_data->mlx_img->img_ptr, 0, 0);
	return (0);
}
