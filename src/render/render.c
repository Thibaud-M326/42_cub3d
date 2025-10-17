/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/17 19:02:02 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "minimap.h"
#include "mlx.h"

int	render(t_data *data)
{
	draw_floor_ceiling(data);
	raycasting(data);
	draw_minimap(data);
	mlx_put_image_to_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr,
		data->mlx_data->mlx_img->img_ptr, 0, 0);
	mlx_put_image_to_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr,
		data->minimap->img->img_ptr, WIDTH / 30, HEIGHT / 30);
	return (0);
}
