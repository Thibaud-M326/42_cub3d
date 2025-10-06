/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/02 22:01:43 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <math.h>
#include <stdlib.h>
#include <X11/keysym.h>

	#include <stdio.h>

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

int	player_offset_pos(t_data *data)
{
	t_player	*player;	

	player = data->player;
	player->offset_pos_x = player->pos_x - player->ray.map_check_x;
	player->offset_pos_y = player->pos_y - player->ray.map_check_y;
	// printf("player->offset_pos_x : %f\n", player->offset_pos_x);
	// printf("player->offset_pos_y : %f\n", player->offset_pos_y);
	return (0);
}

int	ray_unit_length(t_data *data)
{
	t_ray	ray;

	ray = data->player->ray;

	//tant qu'on a un seul ray tout droit
	ray.dir_x = data->player->dir_x;
	ray.dir_y = data->player->dir_y;
	//

	ray.unit_length_x = sqrt(1 + (ray.dir_y / ray.dir_x) * (ray.dir_y / ray.dir_x));
	ray.unit_length_y = sqrt(1 + (ray.dir_x / ray.dir_y) * (ray.dir_x / ray.dir_y));
	// printf("ray.unit_length_x : %f\n", ray.unit_length_x);
	// printf("ray.unit_length_y : %f\n", ray.unit_length_y);
	return (1);
}

int	player_map_pos(t_data *data)
{
	t_player	*player;

	player = data->player;

	player->ray.map_check_x = floor(player->pos_x);
	player->ray.map_check_y = floor(player->pos_y);
	// printf("player->map_pos_x : %f\n", player->map_pos_x);
	// printf("player->map_pos_y : %f\n", player->map_pos_y);
	return (1);
}

int	first_side_ray_dist(t_data *data)
{
	t_ray	ray;

	ray = data->player->ray;

	//tant qu'on a un seul ray tout droit
	ray.dir_x = data->player->dir_x;
	ray.dir_y = data->player->dir_y;
	//

	if (ray.dir_x < 0)
		ray.length_x = data->player->offset_pos_x * ray.unit_length_x;
	else
		ray.length_x = (1 - data->player->offset_pos_x) * ray.unit_length_x;
	if (ray.dir_y < 0)
		ray.length_y = data->player->offset_pos_y * ray.unit_length_y;
	else
		ray.length_y = (1 - data->player->offset_pos_y) * ray.unit_length_y;
	return (1);
}

// if (rayLength.x < rayLength.y) {
	// mapCheck.x += step.x
	// rayLength.x += rayUnitStepSize.x
// } else {
	// mapCheck.y += step.y
	// rayLength.y += rayUnitStepSize.y
// }

//on va prendre la position 
int	hit_wall(t_data *data)
{
	int		**map;
	t_ray	ray;

	map = data->map->map;
	ray = data->player->ray;
	if (map[(int)ray.map_check_y][(int)ray.map_check_x] == 1)
		return (0);
	else
		return (1);
}

//je veut dessiner le rayon
//je dois additioner les deux longueur ray.length x et y 
//partie de la position du joueur et dessiner point par point le trait du rayon
//
int	draw_ray(t_data *data)
{
	t_player	*player;
	t_ray		ray;
	double		total_ray_length;
	double		ray_pixel_x;
	double		ray_pixel_y;

	player = data->player;
	ray = player->ray;
	total_ray_length = ray.length_x + ray.length_y;

	//tant qu'on a un seul ray tout droit
	ray.dir_x = data->player->dir_x;
	ray.dir_y = data->player->dir_y;
	//

	ray_pixel_x = player->pos_x + ray.dir_x + 100;
	ray_pixel_y = player->pos_y + ray.dir_y + 100;
	while (total_ray_length)
	{
		put_one_pixel(data, ray_pixel_x, ray_pixel_y, 0x00FF00);
		ray_pixel_x += ray.dir_x;
		ray_pixel_y += ray.dir_y;
		total_ray_length--;
	}
	return (1);
}

int	hit_wall_ray_dist(t_data *data)
{
	t_ray	ray;

	ray = data->player->ray;
	while (!hit_wall(data))
	{
		if (ray.length_x < ray.length_y)		
		{
			ray.map_check_x += ray.sign_x;
			ray.length_x += ray.unit_length_x;
		}
		else
		{
			ray.map_check_y += ray.sign_y;
			ray.length_y += ray.unit_length_y;
		}
	}
	draw_ray(data);
	return(1);
}

int	raycasting(t_data *data)
{
	ray_sign(data);
	player_map_pos(data);
	ray_unit_length(data);
	player_offset_pos(data);

	return (1);
}

int	render(t_data *data)
{
	draw_cub2d(data);
	player_print(data, data->player);
	raycasting(data);

	mlx_put_image_to_window(data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr, data->mlx_data->mlx_img->img_ptr, 0, 0);
	return (0);
}
