/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/07 16:32:49 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <math.h>
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

int	ray_step(t_data *data)
{
	t_player	*player;

	player = data->player;
	if (player->ray.dir_x >= 0)
		player->ray.step_x = 1;
	else
		player->ray.step_x = -1;
	if (player->ray.dir_y >= 0)
		player->ray.step_y = 1;
	else
		player->ray.step_y = -1;
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

	if (fabs(ray->dir_x) == 0)
		ray->unit_length_x = 1e30;
	else
		ray->unit_length_x = fabs(1.0 / ray->dir_x);
	
	if (fabs(ray->dir_y) == 0)
		ray->unit_length_y = 1e30;
	else
		ray->unit_length_y = fabs(1.0 / ray->dir_y);
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
	int			steps;
	int			i;
	double		t;
	int			px, py;

	ray = &data->player->ray;
	player = data->player;
	steps = (int)(ray->distance * 100);
	
	printf("Drawing ray from (%.1f, %.1f) distance %.3f (%d steps)\n",
		player->pos_x, player->pos_y, ray->distance, steps);
	
	i = 0;
	while (i <= steps)
	{
		t = (double)i / steps;
		
		px = (int)((player->pos_x + ray->dir_x * ray->distance * t) * 100);
		py = (int)((player->pos_y + ray->dir_y * ray->distance * t) * 100);
		
		if (px >= 0 && px < 1000 && py >= 0 && py < 1000)
			put_one_pixel(data, px, py, 0x0000FF);
		
		i++;
	}
	return (1);
}

int	compute_ray_distance(t_data *data)
{
	t_ray	*ray;

	ray = &data->player->ray;
	if (ray->length_x < ray->length_y)
		data->player->ray.distance = ray->length_x;
	else
		data->player->ray.distance = ray->length_y;
	return (1);
}

int	hit_wall(t_data *data)
{
	int		**map;
	t_ray	*ray;

	map = data->map->map;
	ray = &data->player->ray;

	printf("map[%d][%d]\n",(int)ray->map_check_y,(int)ray->map_check_x);

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
			ray->map_check_x += ray->step_x;
			ray->length_x += ray->unit_length_x;
		}
		else
		{
			ray->map_check_y += ray->step_y;
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

	ray_step(data);
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
