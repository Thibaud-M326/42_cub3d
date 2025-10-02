/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/02 18:21:20 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdlib.h>
#include <X11/keysym.h>

int	player_print(t_data *data, t_player *player)
{
	double	pixel_x;
	double	pixel_y;
	
	pixel_x = player->pos_x * data->mlx_data->mlx_img->width / 10;
	pixel_y = player->pos_y * data->mlx_data->mlx_img->height / 10;

	put_one_pixel(data, pixel_x, pixel_y, 0xFF0000);
	put_one_pixel(data, pixel_x + 1, pixel_y + 1, 0xFF0000);
	put_one_pixel(data, pixel_x + 1, pixel_y, 0xFF0000);
	put_one_pixel(data, pixel_x, pixel_y + 1, 0xFF0000);
	return (0);
}

int	ray_sign(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (player->ray.dir_x >= 0)
		player->ray.sign_x = 1;
	else
		player->ray.sign_x = -1;
	if (player->ray.dir_y >= 0)
		player->ray.sign_y = 1;
	else
		player->ray.sign_y = -1;
	return (1);
}

int	draw_ray(t_data *data)
{
	(void)data;	
	return (1);
}

int	render(t_data *data)
{
	draw_cub2d(data);
	player_print(data, data->player);
	draw_ray(data);

	mlx_put_image_to_window(data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr, data->mlx_data->mlx_img->img_ptr, 0, 0);
	return (0);
}
