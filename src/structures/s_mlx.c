/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_mlx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 19:33:22 by thmaitre          #+#    #+#             */
/*   Updated: 2025/10/01 19:11:53 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#include "libft.h"
#include "mlx.h"
#include "mlx_int.h"

int	mlx_start(t_mlx_data *mlx_data, t_mlx_img *mlx_img)
{
	mlx_img->width = 1000;
	mlx_img->height = 1000;
	mlx_data->mlx_img = mlx_img;
	mlx_data->mlx_ptr = mlx_init();
	if (NULL == mlx_data->mlx_ptr)
		return (0);
	mlx_data->win_ptr = mlx_new_window(mlx_data->mlx_ptr, mlx_img->width,
			mlx_img->height, "fractol");
	if (NULL == mlx_data->win_ptr)
		return (0);
	mlx_img->img_ptr = mlx_new_image(mlx_data->mlx_ptr, mlx_img->width,
			mlx_img->height);
	if (NULL == mlx_img->img_ptr)
		return (0);
	mlx_img->endian = 1;
	mlx_img->img_data = mlx_get_data_addr(mlx_img->img_ptr,
			&mlx_img->bits_per_pixel, &mlx_img->size_line, &mlx_img->endian);
	if (NULL == mlx_img->img_data)
		return (0);
	return (1);
}

int	init_mlx(t_data *data)
{
	data->mlx_data = ft_calloc(1, sizeof(t_mlx_data));
	if (!data->mlx_data)
		return (0);
	data->mlx_data->mlx_img = ft_calloc(1, sizeof(t_mlx_img));
	if (!data->mlx_data->mlx_img)
		return (0);
	if (!mlx_start(data->mlx_data, data->mlx_data->mlx_img))
		return (0);
	return (1);
}

int	free_mlx_data(t_mlx_data *mlx_data)
{
	if (mlx_data->mlx_img && mlx_data->mlx_img->img_ptr)
		mlx_destroy_image(mlx_data->mlx_ptr, mlx_data->mlx_img->img_ptr);
	if (mlx_data->win_ptr)
		mlx_destroy_window(mlx_data->mlx_ptr, mlx_data->win_ptr);
	if (mlx_data->mlx_ptr)
		mlx_destroy_display(mlx_data->mlx_ptr);
	free(mlx_data->mlx_ptr);
	if (mlx_data->mlx_img)
	{
		free(mlx_data->mlx_img);
		mlx_data->mlx_img = NULL;
	}
	if (mlx_data)
	{
		free(mlx_data);
		mlx_data = NULL;
	}
	return (1);
}
