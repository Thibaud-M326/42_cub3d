/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/06 19:06:26 by thmaitre         ###   ########.fr       */
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

int	player_map_pos(t_data *data)
{
	t_player	*player;

	player = data->player;

	player->ray.map_check_x = floor(player->pos_x);
	player->ray.map_check_y = floor(player->pos_y);
	return (1);
}

int	ray_unit_length(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;

	ray->unit_length_x = sqrt(1 + (ray->dir_y / ray->dir_x) * (ray->dir_y / ray->dir_x));
	ray->unit_length_y = sqrt(1 + (ray->dir_x / ray->dir_y) * (ray->dir_x / ray->dir_y));
	return (1);
}

int	player_offset_pos(t_data *data)
{
	t_player	*player;	

	player = data->player;
	player->offset_pos_x = player->pos_x - player->ray.map_check_x;
	player->offset_pos_y = player->pos_y - player->ray.map_check_y;
	return (0);
}

int	first_side_ray_dist(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;

	if (ray->dir_x < 0)
		ray->length_x = data->player->offset_pos_x * ray->unit_length_x;
	else
		ray->length_x = (1 - data->player->offset_pos_x) * ray->unit_length_x;
	if (ray->dir_y < 0)
		ray->length_y = data->player->offset_pos_y * ray->unit_length_y;
	else
		ray->length_y = (1 - data->player->offset_pos_y) * ray->unit_length_y;
	return (1);
}

int	draw_ray(t_data *data)
{
	t_ray		*ray;
	t_player	*player;
	int			pixel_distance;
	int			pixel_x;
	int			pixel_y;

	ray = &data->player->ray;
	player = data->player;
	pixel_distance = ray->distance * 100;
	pixel_x = 0;
	pixel_y = 0;

	printf("ray.distance : %f\n", ray->distance);
	printf("pixel_distance : %d\n", pixel_distance);
	printf("player->pos_x :%f\n", player->pos_x);
	printf("player->pos_y :%f\n", player->pos_y);

	while (pixel_distance)	
	{
		put_one_pixel(data, (int)(player->pos_x * 100 + pixel_x) , (int)(player->pos_y * 100 + pixel_y) ,0x0000FF);
		pixel_x += player->dir_x;
		pixel_y += player->dir_y;
		pixel_distance--;
	}
	return (1);
}

int	compute_ray_distance(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->length_x < ray->length_y)
		data->player->ray.distance = ray->length_x - ray->unit_length_x;
	else
		data->player->ray.distance = ray->length_y - ray->unit_length_y;
	return (1);
}

int	hit_wall(t_data *data)
{
	int		**map;
	t_ray	*ray;

	map = data->map->map;
	ray = &data->player->ray;
	if (map[(int)ray->map_check_y][(int)ray->map_check_x] == 1)
		return (1);
	else
		return (0);
}

int	hit_wall_ray_dist(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;
	while (!hit_wall(data))
	{
		if (ray->length_x < ray->length_y)		
		{
			ray->map_check_x += ray->sign_x;
			ray->length_x += ray->unit_length_x;
		}
		else
		{
			ray->map_check_y += ray->sign_y;
			ray->length_y += ray->unit_length_y;
		}
	}
	compute_ray_distance(data);
	draw_ray(data);
	return(1);
}

int	raycasting(t_data *data)
{	
	//tant qu'on a un seul ray droit devant le joueur
	//on devra ensuite faire un tableau de ray
	data->player->ray.dir_x = data->player->dir_x;
	data->player->ray.dir_y = data->player->dir_y;
	//

	ray_sign(data);
	player_map_pos(data);
	ray_unit_length(data);
	player_offset_pos(data);
	first_side_ray_dist(data);
	hit_wall_ray_dist(data);

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
