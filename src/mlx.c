/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vscode <vscode@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 22:01:20 by vscode            #+#    #+#             */
/*   Updated: 2025/09/27 22:45:20 by vscode           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "mlx.h"
#include "mlx_int.h"

void	free_mlx_quit(t_mlx_data *mlx_data, int stop)
{
	if (stop == 1)
	{
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		exit(1);
	}
	else if (stop == 2)
	{
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		exit(1);
	}
	else if (stop == 3)
	{
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->mlx_img->img_ptr);
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
		mlx_destroy_display(mlx_data->mlx_ptr);
		free(mlx_data->mlx_ptr);
		exit(1);
	}
}

int	mlx_start(t_mlx_data *mlx_data, t_mlx_img *mlx_img)
{
	mlx_img->width = 1000;
	mlx_img->height = 1000;
	mlx_data->mlx_img = mlx_img;
	mlx_data->mlx_ptr = mlx_init();
	if (NULL == mlx_data->mlx_ptr)
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, mlx_img->width,
			mlx_img->height, "cub3d");
	if (NULL == mlx_data->win_ptr)
		free_mlx_quit(mlx_data, 1);
	mlx_img->img_ptr = mlx_new_image(mlx_data->mlx_ptr, mlx_img->width,
			mlx_img->height);
	if (NULL == mlx_img->img_ptr)
		free_mlx_quit(mlx_data, 2);
	mlx_img->endian = 1;
	mlx_img->img_data = mlx_get_data_addr(mlx_img->img_ptr,
			&mlx_img->bits_per_pixel, &mlx_img->size_line, &mlx_img->endian);
	if (NULL == mlx_img->img_data)
		free_mlx_quit(mlx_data, 3);
	return (1);
}
