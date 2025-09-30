/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:33:22 by thmaitre          #+#    #+#             */
/*   Updated: 2025/09/30 22:49:23 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include "mlx_int.h"

void	free_mlx(t_data *data, int stop)
{
	if (stop == 1)
	{
		mlx_destroy_display(data->mlx_data->mlx_ptr);
		free(data->mlx_data->mlx_ptr);
	}
	else if (stop == 2)
	{
		mlx_destroy_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr);
		mlx_destroy_display(data->mlx_data->mlx_ptr);
		free(data->mlx_data->mlx_ptr);
	}
	else if (stop == 3)
	{
		mlx_destroy_image(data->mlx_data->mlx_ptr, data->mlx_data->mlx_img->img_ptr);
		mlx_destroy_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr);
		mlx_destroy_display(data->mlx_data->mlx_ptr);
		free(data->mlx_data->mlx_ptr);
	}
	// free_and_exit(data, -1, 1);
}

int	mlx_start(t_data *data)
{
	data->mlx_data->mlx_img->width = 1000;
	data->mlx_data->mlx_img->height = 1000;
	data->mlx_data->mlx_img = data->mlx_data->mlx_img;
	data->mlx_data->mlx_ptr = mlx_init();
	if (NULL == data->mlx_data->mlx_ptr)
		return (0);
	data->mlx_data->win_ptr = mlx_new_window(data->mlx_data->mlx_ptr, data->mlx_data->mlx_img->width,
			data->mlx_data->mlx_img->height, "cub3d");
	if (NULL == data->mlx_data->win_ptr)
		free_mlx(data, 1);
	data->mlx_data->mlx_img->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr, data->mlx_data->mlx_img->width,
			data->mlx_data->mlx_img->height);
	if (NULL == data->mlx_data->mlx_img->img_ptr)
		free_mlx(data, 2);
	data->mlx_data->mlx_img->endian = 1;
	data->mlx_data->mlx_img->img_data = mlx_get_data_addr(data->mlx_data->mlx_img->img_ptr,
			&data->mlx_data->mlx_img->bits_per_pixel, &data->mlx_data->mlx_img->size_line, &data->mlx_data->mlx_img->endian);
	if (NULL == data->mlx_data->mlx_img->img_data)
		free_mlx(data, 3);
	return (1);
}
