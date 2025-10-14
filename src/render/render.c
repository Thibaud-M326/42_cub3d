/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/14 19:59:24 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"

int	render(t_data *data)
{
	draw_floor_ceiling(data);
	raycasting(data);
	mlx_put_image_to_window(
		data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr,
		data->mlx_data->mlx_img->img_ptr,
		0, 0);
	return (0);
}
