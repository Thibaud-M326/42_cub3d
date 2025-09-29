/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:49:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025/09/29 20:14:05 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include <stdlib.h>

int	**create_map(void)
{
	int	**map;
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = malloc(sizeof(int*) * 10);
	if (!map)
		return (NULL);
	while (i < 10)
	{
		map[i] = malloc(sizeof(int) * 10);
		if (!map[i])
		{
			while (--i >= 0)
			{
				free(map[i]);
				return (NULL);
			}
		}
		i++;
	}
	int temp_map[10][10] = {
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1 ,1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			map[i][j] = temp_map[i][j];
			j++;
		}
		i++;
	}
	return (map);
}

int	render(t_mlx_data *mlx_data)
{
	int	x;
	int	y;
	int	**map;
	int	color;

	x = 0;
	y = 0;
	map = create_map();
	color = mix_color(150, 120, 45);
	while (x < 1000)
	{
		put_one_pixel(mlx_data->mlx_img, x, 50, color);
		x++;
	}
	mlx_put_image_to_window(mlx_data->mlx_ptr, mlx_data->win_ptr, mlx_data->mlx_img->img_ptr, 0, 0);
	return (0);
}
